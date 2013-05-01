<?php

function _r2ep_donation_form(&$form, &$form_state, $form_id) {
	$form['#attached']['js'][] = drupal_get_path('module', 'r2ep'). '/js/donate_form.js';
	$form['#attached']['css'][] = drupal_get_path('module', 'r2ep'). '/css/donate_form.css';

	$form['submitted']['pages']['page1'][] = $form['submitted']['message'];
	unset($form['submitted']['message']);
	$form['submitted']['pages']['page1'][] = $form['submitted']['anonymous'];
	unset($form['submitted']['anonymous']);

	$form['pages'] = array(
		'#prefix' => '<div class="pages"><div>',
		'#suffix' => '</div></div>',
	);

	$form['pages']['page1'] = array(
		'#prefix' => '<div class="page">',
		'#suffix' => '</div>',
	);
	$form['pages']['page1'][] = $form['submitted'];
	unset($form['submitted']);
	$form['pages']['page1'][] = $form['wfbs_payment_details']['wfbs_set_price'];
	$form['pages']['page1'][] = $form['wfbs_payment_details']['wfbs_reoccuring'];
	$form['pages']['page1'][] = array(
		'#type' => 'markup',
		'#markup' => '<a class="nextButton">Next Page</a>',
	);

	$form['pages']['page2'] = array(
		'#prefix' => '<div class="page">',
		'#suffix' => '</div>',
	);
	$form['pages']['page2'][] = $form['wfbs_personal_info'];
	unset($form['wfbs_personal_info']);
	$form['pages']['page2'][] = $form['wfbs_payment_details'];
	unset($form['wfbs_payment_details']);
	$form['pages']['page2'][] = array(
		'#type' => 'markup',
		'#markup' => '<a class="nextButton">Next Page</a>',
	);
	$form['pages']['page2'][] = array(
		'#type' => 'markup',
		'#markup' => '<a class="prevButton">Prev Page</a>',
	);



	$form['pages']['page3'] = array(
		'#prefix' => '<div class="page">',
		'#suffix' => '</div>',
	);
	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<p class="namePreview"></p>'
	);
	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<p class="moneyPreview"></p>'
	);
	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<p class="addressPreview"></p>'
	);
	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<p class="cardPreview"></p>'
	);
	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<a class="prevButton">Prev Page</a>',
	);
	$form['pages']['page3'][] = $form['actions'];
	unset($form['actions']);

}