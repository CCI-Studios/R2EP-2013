<?php
/**
 * @file
 * r2ep_profile_header_image.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_profile_header_image_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'profile_header_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Profile Header image';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Profile Header image';
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
  /* Sort criterion: Content: Make this my active R2EP campaign (field_active_campaign) */
  $handler->display->display_options['sorts']['field_active_campaign_value']['id'] = 'field_active_campaign_value';
  $handler->display->display_options['sorts']['field_active_campaign_value']['table'] = 'field_data_field_active_campaign';
  $handler->display->display_options['sorts']['field_active_campaign_value']['field'] = 'field_active_campaign_value';
  $handler->display->display_options['sorts']['field_active_campaign_value']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
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
    'campaign' => 'campaign',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['profile_header_image'] = array(
    t('Master'),
    t('Profile Header image'),
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
  $export['profile_header_image'] = $view;

  return $export;
}
