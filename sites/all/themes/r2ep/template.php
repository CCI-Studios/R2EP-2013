<?php

function r2ep_form_alter(&$form, &$form_state, $form_id) {

	// modify search form
	if ($form_id == 'search_block_form') {
		// HTML5 placeholder attribute
		$form['search_block_form']['#attributes']['placeholder'] = t('Search');
	}
}

function r2ep_preprocess_page(&$variables) {
	$arg = arg();
	if ($arg[0] == 'user' && is_numeric($arg[1]) && empty($arg[2])) {
		$profile = profile2_load_by_user($arg[1], 'main');
		$first = $profile->field_first_name['und'][0]['value'];
		$last = $profile->field_last_name['und'][0]['value'];

		if ($first && $last) {
			$name = "$first $last";
		} else {
			$name = "$first$last";
		}

		$variables['title'] = $name;
	}
}
?>