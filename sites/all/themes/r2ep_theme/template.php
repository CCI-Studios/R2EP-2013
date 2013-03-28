<?php

function r2ep_theme_form_alter(&$form, &$form_state, $form_id) {

	// modify search form
	if ($form_id == 'search_block_form') {
		// HTML5 placeholder attribute
		$form['search_block_form']['#attributes']['placeholder'] = t('Search');
	}
}

function r2ep_preprocess_field(&$variables, $hook){

	// remove inline clearfix
    $element = $variables['element'];
    if ($element['#label_display'] == 'inline') {
        $classes_arr = &$variables['classes_array'];
        for ($i = sizeof($classes_arr)-1; $i >= 0; $i--) {
            if( $classes_arr[$i]==='clearfix' ){
                unset($classes_arr[$i]);
                $i=-1;
            }
    }
  }
}