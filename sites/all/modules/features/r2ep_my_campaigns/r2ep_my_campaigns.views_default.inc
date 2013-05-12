<?php
/**
 * @file
 * r2ep_my_campaigns.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_my_campaigns_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Campaigns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Campaigns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['relationships']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['label'] = 'Event';
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => 'event_thumb',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Goal */
  $handler->display->display_options['fields']['field_goal']['id'] = 'field_goal';
  $handler->display->display_options['fields']['field_goal']['table'] = 'field_data_field_goal';
  $handler->display->display_options['fields']['field_goal']['field'] = 'field_goal';
  $handler->display->display_options['fields']['field_goal']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_goal']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Total Donations */
  $handler->display->display_options['fields']['field_total_donations']['id'] = 'field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['table'] = 'field_data_field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['field'] = 'field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['element_type'] = 'span';
  /* Field: Content: Event */
  $handler->display->display_options['fields']['field_event']['id'] = 'field_event';
  $handler->display->display_options['fields']['field_event']['table'] = 'field_data_field_event';
  $handler->display->display_options['fields']['field_event']['field'] = 'field_event';
  $handler->display->display_options['fields']['field_event']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_event']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['fields']['field_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
    'campaign' => 'campaign',
  );
  /* Filter criterion: Content: Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['my_campaigns'] = array(
    t('Master'),
    t('My Campaigns'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Event'),
    t('Goal'),
    t('Total Donations'),
    t('Date'),
    t('All'),
    t('Block'),
  );
  $export['my_campaigns'] = $view;

  return $export;
}
