<?php
/**
 * @file
 * r2ep_campaign_donations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_campaign_donations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campaign_donations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign Donations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaign Donations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
    'field_wfbs_price' => 'field_wfbs_price',
    'field_description' => 'field_description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_wfbs_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_wfbs_price']['id'] = 'field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['table'] = 'field_data_field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['field'] = 'field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['label'] = 'Donation';
  $handler->display->display_options['fields']['field_wfbs_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wfbs_price']['alter']['text'] = '$[field_wfbs_price]';
  $handler->display->display_options['fields']['field_wfbs_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wfbs_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = 'Message';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Price (field_wfbs_price) */
  $handler->display->display_options['sorts']['field_wfbs_price_value']['id'] = 'field_wfbs_price_value';
  $handler->display->display_options['sorts']['field_wfbs_price_value']['table'] = 'field_data_field_wfbs_price';
  $handler->display->display_options['sorts']['field_wfbs_price_value']['field'] = 'field_wfbs_price_value';
  $handler->display->display_options['sorts']['field_wfbs_price_value']['order'] = 'DESC';
  /* Contextual filter: Content: Campaign (field_campaign) */
  $handler->display->display_options['arguments']['field_campaign_target_id']['id'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['arguments']['field_campaign_target_id']['field'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'donation' => 'donation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['campaign_donations'] = array(
    t('Master'),
    t('Campaign Donations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('First Name'),
    t('Last Name'),
    t('Donation'),
    t('$[field_wfbs_price]'),
    t('Message'),
    t('All'),
    t('Block'),
  );
  $export['campaign_donations'] = $view;

  return $export;
}
