<?php
/**
 * @file
 * r2ep_campaign_blocks.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_campaign_blocks_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaigns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'uid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Contextual filter: Content: Event (field_event) */
  $handler->display->display_options['arguments']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['arguments']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['arguments']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['arguments']['field_event_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_event_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_event_target_id']['default_argument_options']['code'] = '$node = node_load(arg(1));
if($node && isset($node->field_event[LANGUAGE_NONE])) {
    return $node->field_event[LANGUAGE_NONE][0][\'target_id\'];
} else { 
    return; 
}';
  $handler->display->display_options['arguments']['field_event_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_target_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['type']['relationship'] = 'uid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'campaign' => 'campaign',
  );

  /* Display: Event Campaigns */
  $handler = $view->new_display('block', 'Event Campaigns', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Event (field_event) */
  $handler->display->display_options['arguments']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['arguments']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['arguments']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['arguments']['field_event_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_event_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Team Campaigns */
  $handler = $view->new_display('block', 'Team Campaigns', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_runners_target_id']['id'] = 'field_runners_target_id';
  $handler->display->display_options['relationships']['field_runners_target_id']['table'] = 'field_data_field_runners';
  $handler->display->display_options['relationships']['field_runners_target_id']['field'] = 'field_runners_target_id';
  $handler->display->display_options['relationships']['field_runners_target_id']['label'] = 'Runners';
  /* Relationship: User: Content authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'field_runners_target_id';
  $handler->display->display_options['relationships']['uid']['label'] = 'Nodes';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $translatables['campaigns'] = array(
    t('Master'),
    t('Campaigns'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Event Campaigns'),
    t('Team Campaigns'),
    t('Runners'),
    t('Nodes'),
  );
  $export['campaigns'] = $view;

  return $export;
}
