<?php

define('TWILIO_SID',    'r2ep_notifications_twilio_sid');
define('TWILIO_TOKEN',  'r2ep_notifications_twilio_token');
define('TWILIO_NUMBER', 'r2ep_notifications_twilio_number');

function _r2ep_notifications_config_form() {
	$form = array();

	$form[TWILIO_SID] = array(
		'#type' => 'textfield',
		'#title' => 'Twilio SID',
		'#default_value' => variable_get(TWILIO_SID, '')
	);

	$form[TWILIO_TOKEN] = array(
		'#type' => 'textfield',
		'#title' => 'Twilio Token',
		'#default_value' => variable_get(TWILIO_TOKEN, '')
	);

	$form[TWILIO_NUMBER] = array(
		'#type' => 'textfield',
		'#title' => 'Twilio Number',
		'#default_value' => variable_get(TWILIO_NUMBER, '')
	);

	return system_settings_form($form);
}


function r2ep_notifications_delete_function($node) {
	// Taken from node modules node_delete_confirm submit handler
	node_delete($node->nid);
	watchdog('content', '@type: deleted %title.', array('@type' => $node->type, '%title' => $node->title));
	// Do a drupal goto here to preserver the 'destination' parameter
	drupal_goto();
}

function _r2ep_notifications_form($form_state) {
	global $user;

	// get list of teams for the signed in user
	$teamQuery = db_select('node')
		->fields('node', array('nid', 'title'))
		->condition('type', 'team')
		->condition('status', 1)
		// ->condition('uid', $user->uid) // allow all access since we are doing admin only
		->orderBy('title');
	$teamOptions = array('0' => 'None');
	foreach($teamQuery->execute() as $team) {
		$teamOptions[$team->nid] = $team->title;
	}

	// get a list of events for the signed in user
	$eventQuery = db_select('node')
		->fields('node', array('nid', 'title'))
		->condition('type', 'event')
		->condition('status', 1)
		// ->condition('uid', $user->uid) // allow all access since we are doing admin only
		->orderBy('title');
	$eventOptions = array('0' => 'None');
	foreach($eventQuery->execute() as $event) {
		$eventOptions[$event->nid] = $event->title;
	}


	$form['intro'] = array(
		'#type' => 'markup',
		'#markup' => '<p>Fill out the form below to send a notification.</p>',
	);

	if (count($teamOptions) > 1) {
		$form['team'] = array(
			'#type' => 'select',
			'#title' => 'Select Team',
			'#options' => $teamOptions,
			'#description' => t('Which team would you like to send this message to.'),
		);
	}

	if (count($eventOptions) > 1) {
		$form['event'] = array(
			'#type' => 'select',
			'#title' => 'Select Event',
			'#options' => $eventOptions,
			'#description' => t('Which event would you like to send this message to.'),
		);
	}

	$form['message'] = array(
		'#type' => 'textfield',
		'#title' => t('Message'),
		'#required' => true,
		'#maxlength' => 140,
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Send'),
	);

	return $form;
}

// function _r2ep_notifications_form_validate($form, &$form_state) {}

function _r2ep_notifications_form_submit($form, &$form_state) {
	$team = $form_state['values']['team'];
	$event = $form_state['values']['event'];
	$message = $form_state['values']['message'];

	// check that user can edit team page
	if ($team && !_r2ep_validate_team($team)) {
		$team = false;
	}

	// check that user can edit event page
	if ($event && !_r2ep_validate_event($event)) {
		$event = false;
	}

	// if they dont want to do anything, dont do anything
	if ($team == 0 && $event == 0) {
		return;
	}

	$runners = array();

	if ($team) {
		$team = node_load($team);
		$rField = field_get_items('node', $team, 'field_runners');

		foreach($rField as $runner) {
			$runners[] = (int)$runner['target_id'];
		}
	}

	if ($event) {
		$query = db_select('node', 'n')
			->fields('n', array('uid'))
			->condition('type', 'campaign')
			->condition('e.field_event_target_id', $event);
		$query->leftJoin('field_data_field_event', 'e', 'e.entity_id = n.nid');

		$users = $query->execute()->fetchCol();
		$runners = array_merge($runners, $users);
	}

	$runners = array_unique($runners);
	$users = user_load_multiple($runners);

	$path = libraries_get_path('twilio');
	require_once(DRUPAL_ROOT .'/'. $path .'/Services/Twilio.php');
	$sid = variable_get(TWILIO_SID, '');
	$token = variable_get(TWILIO_TOKEN, '');
	$from = variable_get(TWILIO_NUMBER, '');
	$client = new Services_Twilio($sid, $token);

	// load twillo
	foreach($users as $user) {
		$notification = new stdClass();
		$notification->title = "Notification";
		$notification->type = "notification";
		node_object_prepare($notification);

		$notification->language = LANGUAGE_NONE;
		$notification->uid = $user->uid;
		$notification->status = 1;
		$notification->promote = 0;
		$notification->comment = 1;
		$notification->field_description = array(
			'und' => array(array(
				'value' => $message,
			))
		);

		$notification = node_submit($notification);
		node_save($notification);

		$cell = field_get_items('user', $user, 'field_cell_number');
		if ($cell && count($cell)) {
			$number = $cell[0]['value'];
			$message = $client->account->sms_messages->create(
				$from,
				$number,
				$message
			);
		}
	}

	drupal_set_message(count($users) .' users notified.');
}

function _r2ep_validate_team($team_id) {
	global $user;
	$team = node_load($team_id);

	if ($team->uid == $user->uid && $team->type == 'team') {
		return true;
	} else {
		return false;
	}
}

function _r2ep_validate_event($event_id) {
	global $user;
	$event = node_load($event_id);

	if ($event->uid == $user->uid && $event->type == 'event') {
		return true;
	} else {
		return false;
	}
}