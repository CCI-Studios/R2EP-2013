<?php

function _r2ep_donation_form(&$form, &$form_state, $form_id) {
	// $form['#attached']['js'][] = drupal_get_path('module', 'r2ep'). '/js/donate_form.js';
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
<p>Donating As: <span class="namePreview"></span></p>
<p>Donation Message: <span class="messagePreview"></span></p>
<p>Donation Amount: <span class="donationPreview"></span> via <span class="typePreview"></span></p>
<p>
	<strong>Receipting Information:</strong><br/>
	<span class="addressPreview"></span><br/>
	<span class="cityPreview"></span>, <span class="provincePreview"></span><br/>
	<span class="postalPreview"></span><br/>
	<span class="phonePreview"></span>, <span class="emailPreview"></span>
</p>
<p>Please click submit only once to avoid multiple transactions</p>
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
	global $base_url;
	$nid = arg(1);
	$node = node_load($nid);
	$user = user_load($node->uid);
	$name = $user->realname;
	$gif = $base_url ."/contacts/share/opened/[views-send:nid]";
	$url = $base_url ."/contacts/share/clicked/[views-send:nid]";

	$form['to']['views_send_to_name']['#default_value'] = 'field_first_name_pos_1';
	$form['to']['views_send_to_mail']['#default_value'] = 'field_contact_email_pos_3';

	$form['mail']['views_send_subject']['#default_value'] = 'You can drive the impact of my run!';
	$form['mail']['views_send_message']['#format'] = 'full_html';
	$form['mail']['views_send_message']['#default_value'] = <<<html
<p>Hi [views-send:field_first_name],</p>

<p>This year, I am one of hundreds of Canadians participating in Run to End Poverty, a nationwide campaign that seeks to bring people together with one common goal: to eliminate extreme poverty in rural Africa. You can be the driving force that makes this possible. The system of poverty is incredibly complex and rather than shying away from this, I have decided to embrace it. I have decided to courageously commit to joining this movement in order to support the incredible work of Engineers Without Borders. You can amplify the impact of each stride by donating to my run. Your donation will enable innovative approaches to deliver impactful and sustainable solutions. Together we have the potential to bring about a positive change in our world.</p>

<p>Please read my <a href="$url">reason for running</a>.</p>

<p>Support smart development by making a donation to Engineers Without Borders today. It's simple and easy - all you have to do is click the <a href="$url">donate now button</a>.</p>

<p>Feel free to ask me any questions you might have - this isn't just about money. When you donate to EWB you are helping to create lasting change, not ongoing charity.</p>

<p>Thanks for your support,<br/>
$name</p>
<img src="$gif" width="0" height="0" />
html;
}