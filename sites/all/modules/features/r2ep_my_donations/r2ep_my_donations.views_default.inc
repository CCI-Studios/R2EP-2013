<?php
/**
 * @file
 * r2ep_my_donations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_my_donations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_donations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Donations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Donations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-1-3';
  $handler->display->display_options['style_options']['class'] = 'gridContainer mediaList';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_campaign_target_id']['id'] = 'field_campaign_target_id';
  $handler->display->display_options['relationships']['field_campaign_target_id']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['relationships']['field_campaign_target_id']['field'] = 'field_campaign_target_id';
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avatar']['element_wrapper_class'] = 'mediaList-image';
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'event_thumb',
    'image_link' => '',
  );
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_wfbs_price']['id'] = 'field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['table'] = 'field_data_field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['field'] = 'field_wfbs_price';
  $handler->display->display_options['fields']['field_wfbs_price']['label'] = '';
  $handler->display->display_options['fields']['field_wfbs_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wfbs_price']['alter']['text'] = '$[field_wfbs_price-value] ';
  $handler->display->display_options['fields']['field_wfbs_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wfbs_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
  $translatables['my_donations'] = array(
    t('Master'),
    t('My Donations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_campaign'),
    t('$[field_wfbs_price-value] '),
    t('All'),
    t('Block'),
  );
  $export['my_donations'] = $view;

  return $export;
}
