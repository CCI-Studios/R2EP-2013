<?php

function r2ep_form_alter(&$form, &$form_state, $form_id) {

	// modify search form
	if ($form_id == 'search_block_form') {
		// HTML5 placeholder attribute
		$form['search_block_form']['#attributes']['placeholder'] = t('Search');
	}
}