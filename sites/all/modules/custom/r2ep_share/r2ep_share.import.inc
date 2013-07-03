<?php

function _r2ep_share_import_form($form_state) {
	$cid = isset($_GET['field_campaign'])? $_GET['field_campaign'] : 0;
	$campaign = node_load($cid);
	$form = array();
	if (!$campaign) {
		return $form;
	}

	$form['intro'] = array(
		'#markup' => t("Import emails for {$campaign->title}"),
		'#prefix' => '<h2>',
		'#suffix' => '</h2>'
	);

	$form['addresses'] = array(
		'#title' => t('Email Addresses'),
		'#type' => 'textarea',
		'#description' => t('Enter email addresses,one per line, to import into this campaign.'),
	);

	$form['campaign_id'] = array(
		'#title' => t(''),
		'#type' => 'hidden',
		'#default_value' => $cid,
		'#required' => true,
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Import'),
	);

	return $form;
}

function _r2ep_share_import_form_validate($form, &$form_state) {
	// check emails
	$emails = explode("\r\n", $form_state['values']['addresses']);
	$validEmails = array_filter(filter_var_array($emails, FILTER_VALIDATE_EMAIL, FALSE), 'strlen');
	$invalidEmails = array_diff($emails, $validEmails);
	if (count($invalidEmails)) {
		form_set_error('r2ep_share', 'Some addresses were invalid: '. implode(", ", $invalidEmails));
	}

}

function _r2ep_share_import_form_submit($form, &$form_state) {
	global $user;

	// get a list of all valid emails
	$emails = explode("\r\n", $form_state['values']['addresses']);
	$validEmails = array_filter(filter_var_array($emails, FILTER_VALIDATE_EMAIL, FALSE), 'strlen');

	$cid = $form_state['values']['campaign_id'];

	$eValues = array(
		'type' => 'campaign_contact',
		'uid' => $user->uid,
		'status' => 1,
		'comment' => 0,
		'promote' => 0,
	);

	foreach($emails as $email) {
		$entity = entity_create('node', $eValues);
		$eWrapper = entity_metadata_wrapper('node', $entity);

		$eWrapper->field_contact_email->set($email);
		$eWrapper->field_campaign->set(intval($cid));
		$eWrapper->save(true);
		entity_save('node', $entity);
	}

	$form_state['redirect'] = "/share/$cid";
}