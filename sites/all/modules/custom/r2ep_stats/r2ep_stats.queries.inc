<?php

 // runners
function _r2ep_stats_get_runner_count($type = null, $ref = null) {
	$runners = array();

	switch($type) {
		case 'TEAM':
			if ($ref && $ref->field_runners) {
				$runners = count($ref->field_runners['und']);
			}
			break;
		case 'EVENT': // works
			$query = new EntityFieldQuery();
			$query->entityCondition('entity_type', 'node')
				->entityCondition('bundle', 'campaign')
				->propertyCondition('status', 1)
				->fieldCondition('field_event', 'target_id', $ref);
			$runners = $query->count()->execute();
			break;
		case 'NATIONAL': // works
			$runners = db_query("SELECT count(uid) FROM {users} where status = 1")->fetchField();
			break;
	}

	return $runners;
}


function _r2ep_stats_get_campaigns_for_event($id) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign')
		->propertyCondition('status', 1)
		->fieldCondition('field_event', 'target_id', $id);

	$result = $query->execute();

	if ($result['node']) {
		return $result['node'];
	} else {
		return array();
	}
}

function _r2ep_stats_get_team_count($type) {
	$teams = array();

	switch($type) {
		case 'TEAM':
		case 'EVENT':
		case 'RUNNER':
		case 'NATIONAL':
			$teams = db_query("SELECT count(nid) FROM {node} WHERE type = 'team' AND status = 1")->fetchField();
	}

	return $teams;
}



// CRUFTY
// get stats
function _r2ep_stats_get_runners($type = null) {
	$runners = array();

	switch($type) {
		case 'TEAM':
			$node = menu_get_object();
			if ($node && isset($node->field_runners['und'])) {
				foreach ($node->field_runners['und'] as $field) {
					$runners[] = $field['target_id'];
				}
			}
			break;
		case 'EVENT':
		case 'NATIONAL':
			$runners = db_query("SELECT uid FROM {users} where status = 1")->fetchCol();
	}

	return $runners;
}

function _r2ep_stats_get_teams($type = null) {
	$teams = array();

	switch($type) {
		case 'TEAM':
		case 'EVENT':
		case 'RUNNER':
		default:
			$teams = db_query("SELECT nid FROM {node} WHERE type = 'team' AND status = 1")->fetchCol();
	}

	return $teams;
}

function _r2ep_stats_get_campaign_total($type = 'national', $id = null) {

	switch($type) {
		case 'TEAM':
		case 'EVENT':
		case 'RUNNER':
		case 'NATIONAL':
		default:
			$total = db_select('node', 'n')
				->condition('n.type', 'donation')
				->condition('n.status', 1);
			$total->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
			$total->addExpression('sum(p.field_wfbs_price_value)');

			$total = $total->execute()->fetchField();
	}

	setlocale(LC_MONETARY, 'en_US');
	return money_format('%.0n', $total);
}

function _r2ep_stats_get_donation_total($type, $ref = null) {
	$total = 0;

	switch($type) {
		case 'TEAM':
			$total = 100;
			break;
		case 'EVENT':
			$campaigns = _r2ep_stats_get_campaigns_for_event($ref);
			$total = 100;
			break;
		case 'RUNNER':
			$total = 100;
			break;
		case 'NATIONAL':
			$total = db_select('node', 'n')
				->condition('n.type', 'donation')
				->condition('n.status', 1);
			$total->join('field_data_field_wfbs_price', 'p', 'p.entity_id = n.nid');
			$total->addExpression('sum(p.field_wfbs_price_value)');

			$total = $total->execute()->fetchField();
			break;
	}

	setlocale(LC_MONETARY, 'en_US');
	return money_format('%.0n', $total);
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