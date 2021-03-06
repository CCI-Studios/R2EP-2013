<?php

// queryies for event node
function _r2ep_stats_number_of_runners_for_event($event_id) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->fieldCondition('field_event', 'target_id', $event_id);

	return $query->count()->execute();
}

function _r2ep_stats_number_of_teams_for_event($event_id) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'team')
		->propertyCondition('status', 1)
		->fieldCondition('field_event', 'target_id', $event_id);
	$result = $query->execute();

	if (isset($result['node'])) {
		return count($result['node']);
	} else {
		return 0;
	}
}

// queries for user node
function _r2ep_stats_number_of_campaigns_for_user($uid) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('status', 1)
		->propertyCondition('uid', $uid);

	return $query->count()->execute();
}

///////////////////////////////////////////////


function _r2ep_stats_get_all_runners_count() {
	return db_query("SELECT count(*) as 'count'
		from (
  			select uid from node where type='campaign' and status=1 group by uid
		) sq")->fetchField();
}

function _r2ep_stats_get_runners_for_team($teamid) {
	$team = node_load($teamid);
	$runners = array();

	if ($team && $team->field_runners) {
		foreach($team->field_runners['und'] as $runner) {
			$runners[] = (int)$runner['target_id'];
		}
	}

	return $runners;
}

function _r2ep_stats_get_runners_for_event($eventid) {
	$campaigns = _r2ep_stats_get_campaigns_for_event($eventid);
	$runners = array();

	if ($campaigns && count($campaigns)) {
		$query = db_select('node', 'n')
			->fields('n', array('uid'))
			->condition('type', 'campaign')
			->condition('status', 1)
			->condition('nid', $campaigns, 'IN');

		$uids = $query->execute()->fetchCol();
		foreach($uids as $uid) {
			$runners[] = (int)$uid;
		}
	}

	return $runners;
}

// campaigns
function _r2ep_stats_get_campaigns_for_event($eventid) {
	$campaigns = array();

	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('status', 1)
		->fieldCondition('field_event', 'target_id', $eventid);

	$result = $query->execute();

	if (isset($result['node']) && count($result['node'])) {
		$campaigns = array_keys($result['node']);
	}

	return $campaigns;
}

function _r2ep_stats_get_campaigns_for_runners($runners) {

	if (!$runners || !count($runners)) {
		return array();
	}

	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('status', 1)
		->propertyCondition('uid', $runners, 'in');
	$result = $query->execute();

	$campaigns = array();

	if (isset($result['node']) && count($result['node'])) {
		foreach($result['node'] as $node) {
			$campaigns[] = $node->nid;
		}
	}

	return $campaigns;
}

// donations
function _r2ep_stats_get_all_donations_total() {
	$query = db_select('node', 'n')
			->condition('n.type', 'donation')
			->condition('n.created', strtotime(date('Y-1-1')), '>=')
			->condition('n.status', 1);
	$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
	$query->addExpression('sum(p.field_wfbs_price_value)');

	$total = $query->execute()->fetchField();

	setlocale(LC_MONETARY, 'en_US');
	return money_format('%.0n', $total);
}

function _r2ep_stats_get_donations_total_for_runners($runners) {
	$campaigns = _r2ep_stats_get_campaigns_for_runners($runners);

	return _r2ep_stats_get_donations_total_for_campaigns($campaigns);
}

function _r2ep_stats_get_donations_total_for_campaigns($campaigns) {

	if ($campaigns && count($campaigns)) {
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'donation')
			->propertyCondition('status', 1)
			->fieldCondition('field_campaign', 'target_id', $campaigns, 'IN');

		$results = $query->execute();

		if (isset($results['node']) && count($results['node'])) {
			$nids = array_keys($results['node']);

			$query = db_select('node', 'n')
				->condition('nid', $nids, 'IN');
			$query->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
			$query->addExpression('sum(p.field_wfbs_price_value)');

			$total = $query->execute()->fetchField();
		} else {
			$total = 0;
		}
	} else {
		$total = 0;
	}

	setlocale(LC_MONETARY, 'en_US');
	return money_format('%.0n', $total);
}


// teams
function _r2ep_stats_get_all_teams_count() {
	return db_query("SELECT count(nid) FROM {node} WHERE type = 'team' AND status = 1")->fetchField();
}

function _r2ep_stats_get_team_count_for_event($event_id) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'team')
		->propertyCondition('status', 1)
		->fieldCondition('field_event', 'target_id', $event_id);
	$result = $query->execute();

	if (isset($result['node'])) {
		return count($result['node']);
	} else {
		return 0;
	}
}

function _r2ep_stats_get_team_count_for_runners($runners) {
	$teams = _r2ep_stats_get_teams_for_runners($runners);

	return count($teams);
}

function _r2ep_stats_get_teams_for_runners($runners) {
	$teams = array();

	if ($runners && count($runners)) {
		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'team')
			->propertyCondition('status', 1)
			->fieldCondition('field_runners', 'target_id', $runners, 'IN');

		$result = $query->execute();

		if (isset($result['node']) && count($result['node'])) {
			$teams = array_keys($result['node']);
		}
	}

	return $teams;
}

// format content
function _r2ep_stats_block($texts, $images) {
	$path = drupal_get_path('module', 'r2ep_stats');
	$block = array();

	if (count($texts) != count($images)) {
		return $block;
	}

	$block = array(
		'#theme' => 'item_list',
		'#items' => array(),
		'#attributes' => array(
			'class' => 'stats-list'
		),
	);

	for ($i = 0; $i < count($texts); $i++) {
		$text = $texts[$i];
		$image = $images[$i];

		$block['#items'][] = array(
			'data' => "<img src=\"/$path/images/$image.png\" />$text",
			'class' => array($image),
		);
	}

	return $block;
}