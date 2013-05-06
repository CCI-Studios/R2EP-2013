<?php

function _r2ep_donation_form(&$form, &$form_state, $form_id) {
	$form['#attached']['js'][] = drupal_get_path('module', 'r2ep'). '/js/donate_form.js';
	$form['#attached']['css'][] = drupal_get_path('module', 'r2ep'). '/css/donate_form.css';

	$form['pages'] = array(
		'#parent' => false,
		'#prefix' => '<div class="pages"><div>',
		'#suffix' => '</div></div>',
	);

	$form['pages']['page1'] = array(
		'#prefix' => '<div class="page">',
		'#suffix' => '</div>',
	);
	$form['pages']['page1']['submitted'] = $form['submitted'];
	unset($form['submitted']);

	$container = array(
		'#prefix' => '<div class="gridContainer">',
		'#suffix' => '</div>',
	);
	$container[] = $form['wfbs_payment_details']['wfbs_set_price'];
	$container[] = $form['wfbs_payment_details']['wfbs_reoccuring'];
	$container[] = $form['wfbs_payment_details']['wfbs_price'];
	$form['pages']['page1'][] = $container;
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
		'#markup' => <<<HTML
<p>Please review your donation details below and click "Submit Donation":</p>
<p class="namePreview"></p>
<p>
	<span class="addressPreview"></span>, <span class="cityPreview"></span><br/>
	<span class="postalPreview"></span>, <span class="provincePreview"></span><br/>
	<span class="phonePreview"></span>, <span class="emailPreview"></span>
</p>

<p>
	<span class="donationPreview"></span> via <span class="typePreview"></span>
</p>

<p class="messagePreview"></p>
HTML
	);

	$form['pages']['page3'][] = array(
		'#type' => 'markup',
		'#markup' => '<a class="prevButton">Prev Page</a>',
	);
	$form['pages']['page3'][] = $form['actions'];
	// unset($form['actions']);

}

function _r2ep_email_form(&$form, &$form_state, $form_id) {
}