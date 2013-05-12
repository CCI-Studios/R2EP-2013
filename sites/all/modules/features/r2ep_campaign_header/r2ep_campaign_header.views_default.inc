<?php
/**
 * @file
 * r2ep_campaign_header.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_campaign_header_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campaign_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign Header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaign Header';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['relationships']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['label'] = 'Event';
  /* Field: Content: Header Image */
  $handler->display->display_options['fields']['field_header_image']['id'] = 'field_header_image';
  $handler->display->display_options['fields']['field_header_image']['table'] = 'field_data_field_header_image';
  $handler->display->display_options['fields']['field_header_image']['field'] = 'field_header_image';
  $handler->display->display_options['fields']['field_header_image']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['fields']['field_header_image']['label'] = '';
  $handler->display->display_options['fields']['field_header_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_header_image']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_header_image']['settings'] = array(
    'view_mode' => 'full',
    'links' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'campaign' => 'campaign',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['campaign_header'] = array(
    t('Master'),
    t('Campaign Header'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Event'),
    t('All'),
    t('Block'),
  );
  $export['campaign_header'] = $view;

  return $export;
}
