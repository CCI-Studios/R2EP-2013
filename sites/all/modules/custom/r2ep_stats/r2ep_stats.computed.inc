<?php

// DONATIONS TOTAL
function _r2ep_stats_total_donations_user(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('uid', $entity->uid);
	$results = $query->execute();

	if (isset($results['node'])) {
		$campaigns = array_keys($results['node']);

		// sum all donations made to any of the campaigns
		$query = db_select('node', 'n')
			->condition('n.type', 'donation')
			->condition('n.status', 1)
			->condition('c.field_campaign_target_id', $campaigns, 'IN');
		$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');
		$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
		$query->addExpression('sum(p.field_wfbs_price_value)');

		$entity_field[0]['value'] = $query->execute()->fetchField();
	} else {
		$entity_field[0]['value'] = 0;
	}
}

function _r2ep_stats_total_donations_campaign(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = db_select('node', 'n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition('c.field_campaign_target_id', $entity->nid);
	$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');
	$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
	$query->addExpression('sum(p.field_wfbs_price_value)');

	$entity_field[0]['value'] = $query->execute()->fetchField();
}

function _r2ep_stats_total_donations_event(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$or = db_or()
		->condition('event.field_event_target_id', $entity->nid) // event directly matches
		->condition('cevent.field_event_target_id', $entity->nid); // event matches through campaign
	$query = db_select('node', 'n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition($or);
	$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id=n.nid'); // get amounts
	$query->leftJoin('field_data_field_event', 'event', 'event.entity_id=n.nid'); // direct donation (optional)
	$query->leftJoin('field_data_field_campaign', 'cid', 'cid.entity_id=n.nid'); // link to campaigns for indirect donation
	$query->leftJoin('node', 'campaign', 'campaign.nid=cid.field_campaign_target_id');
	$query->leftJoin('field_data_field_event', 'cevent', 'cevent.entity_id=campaign.nid');
	$query->addExpression('sum(p.field_wfbs_price_value)');

	$total = $query->execute()->fetchField();
	$entity_field[0]['value'] = $total;
}

function _r2ep_stats_total_donations_team(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$total = 0;
	$temp = @$entity->field_runners['und'];
	$runners = array();
	if ($temp) {
		foreach ($temp as $runner) {
			$runners[] = (int)$runner['target_id'];
		}
	}

	// get all campaigns for all team members
	if (count($runners) &&
		isset($entity->field_event) &&
		isset($entity->field_event['und']) &&
		count($entity->field_event['und'])) {
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'campaign')
			->propertyCondition('uid', $runners, 'IN')
			->fieldCondition('field_event', 'target_id', $entity->field_event['und'][0]['target_id']);
		$results = $query->execute();

		if (isset($results['node'])) {
			$campaigns = array_keys($results['node']);

			// sum all donations made to any of the campaigns
			$query = db_select('node', 'n')
				->condition('n.type', 'donation')
				->condition('n.status', 1)
				->condition('c.field_campaign_target_id', $campaigns, 'IN');
			$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');
			$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
			$query->addExpression('sum(p.field_wfbs_price_value)');

			$total += $query->execute()->fetchField();
		}
	}

	// add any donations made straight to the team
	$query = db_select('node', 'n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition('t.field_team_target_id', $entity->nid);
	$query->join('field_data_field_team', 't', 't.entity_id = n.nid');
	$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
	$query->addExpression('sum(p.field_wfbs_price_value)');
	$total += $query->execute()->fetchField();
	$entity_field[0]['value'] = $total;
}



// DONATION COUNT
function _r2ep_stats_donation_count_user(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('uid', $entity->uid);
	$results = $query->execute();

	if (isset($results['node'])) {
		$campaigns = array_keys($results['node']);

		// sum all donations made to any of the campaigns
		$query = db_select('node', 'n')
			->fields('n')
			->condition('n.type', 'donation')
			->condition('n.status', 1)
			->condition('c.field_campaign_target_id', $campaigns, 'IN');
		$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');

		$entity_field[0]['value'] = $query->execute()->rowCount();
	} else {
		$entity_field[0]['value'] = 0;
	}
}

function _r2ep_stats_donation_count_campaign(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = db_select('node', 'n')
		->fields('n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition('c.field_campaign_target_id', $entity->nid);
	$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');

	$entity_field[0]['value'] = $query->execute()->rowCount();
}

function _r2ep_stats_donation_count_event(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$total = 0;

	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->fieldCondition('field_event', 'target_id', $entity->nid);
	$results = $query->execute();

	if (isset($results['node'])) {
		$campaigns = array_keys($results['node']);
		$query = db_select('node', 'n')
			->fields('n')
			->condition('type', 'donation')
			->condition('c.field_campaign_target_id', $campaigns, 'IN');
		$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');

		$total += $query->execute()->rowCount();
	}

	// add any donations made straight to the event
	$query = db_select('node', 'n')
		->fields('n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition('e.field_event_target_id', $entity->nid);
	$query->join('field_data_field_event', 'e', 'e.entity_id = n.nid');
	$total += $query->execute()->rowCount();

	$entity_field[0]['value'] = $total;
}

function _r2ep_stats_donation_count_team(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$total = 0;
	$temp = @$entity->field_runners['und'];
	$runners = array();
	if ($temp) {
		foreach ($temp as $runner) {
			$runners[] = (int)$runner['target_id'];
		}
	}

	// get all campaigns for all team members
	if (count($runners) &&
		isset($entity->field_event) &&
		isset($entity->field_event['und']) &&
		count($entity->field_event['und'])) {
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'campaign')
			->propertyCondition('uid', $runners, 'IN')
			->fieldCondition('field_event', 'target_id', $entity->field_event['und'][0]['target_id']);
		$results = $query->execute();

		if (isset($results['node'])) {
			$campaigns = array_keys($results['node']);

			// count all donations made to any of the campaigns
			$query = db_select('node', 'n')
				->fields('n')
				->condition('n.type', 'donation')
				->condition('n.status', 1)
				->condition('c.field_campaign_target_id', $campaigns, 'IN');
			$query->join('field_data_field_campaign', 'c', 'c.entity_id = n.nid');

			$total += $query->execute()->rowCount();
		}
	}

	// add any donations made straight to the team
	$query = db_select('node', 'n')
		->fields('n')
		->condition('n.type', 'donation')
		->condition('n.status', 1)
		->condition('t.field_team_target_id', $entity->nid);
	$query->join('field_data_field_team', 't', 't.entity_id = n.nid');
	$total += $query->execute()->rowCount();

	$entity_field[0]['value'] = $total;
}


// calc total goals
function _r2ep_stats_donation_total_user(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = db_select('node', 'n')
		->condition('n.type', 'campaign')
		->condition('n.uid', $entity->uid);
	$query->join('field_data_field_goal', 'g', 'g.entity_id = n.nid');
	$query->addExpression('sum(g.field_goal_value)');

	$entity_field[0]['value'] = $query->execute()->fetchField();
}

function _r2ep_stats_donation_total_team(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$total = 0;
	$temp = @$entity->field_runners['und'];
	$runners = array();
	if ($temp) {
		foreach ($temp as $runner) {
			$runners[] = (int)$runner['target_id'];
		}
	}

	// get all campaigns for all team members
	if (count($runners) &&
		isset($entity->field_event) &&
		isset($entity->field_event['und']) &&
		count($entity->field_event['und'])) {
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'campaign')
			->propertyCondition('uid', $runners, 'IN')
			->fieldCondition('field_event', 'target_id', $entity->field_event['und'][0]['target_id']);
		$results = $query->execute();

		if (isset($results['node'])) {
			$campaigns = array_keys($results['node']);

			$query = db_select('node', 'n')
				->condition('n.type', 'campaign')
				->condition('n.nid', $campaigns, 'IN');
			$query->join('field_data_field_goal', 'g', 'g.entity_id = n.nid');
			$query->addExpression('sum(g.field_goal_value)');

			$total += $query->execute()->fetchField();
		}
	}

	$entity_field[0]['value'] = $total;
}

function _r2ep_stats_donation_total_event(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
	$query = db_select('node', 'n')
		->condition('n.type', 'campaign')
		->condition('e.field_event_target_id', $entity->nid);
	$query->join('field_data_field_event', 'e', 'e.entity_id = n.nid');
	$query->join('field_data_field_goal', 'g', 'g.entity_id = n.nid');
	$query->addExpression('sum(g.field_goal_value)');

	$entity_field[0]['value'] = $query->execute()->fetchField();
}