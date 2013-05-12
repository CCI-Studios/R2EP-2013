<?php
/**
 * @file
 * r2ep_runners.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_runners_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'newest_runners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Newest Runners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Newest Runners';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-1-3';
  $handler->display->display_options['style_options']['class'] = 'gridContainer';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list thumb-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Content authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_avatar']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_avatar']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'profile_thumbnail',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Make this my active R2EP campaign (field_active_campaign) */
  $handler->display->display_options['filters']['field_active_campaign_value']['id'] = 'field_active_campaign_value';
  $handler->display->display_options['filters']['field_active_campaign_value']['table'] = 'field_data_field_active_campaign';
  $handler->display->display_options['filters']['field_active_campaign_value']['field'] = 'field_active_campaign_value';
  $handler->display->display_options['filters']['field_active_campaign_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_active_campaign_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['newest_runners'] = array(
    t('Master'),
    t('Newest Runners'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('nodes'),
    t('[field_first_name] [field_last_name]'),
    t('Block'),
  );
  $export['newest_runners'] = $view;

  $view = new view();
  $view->name = 'runner_avatar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Runner Avatar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Runner Avatar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'sidebar',
    'image_link' => 'content',
  );
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['runner_avatar'] = array(
    t('Master'),
    t('Runner Avatar'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  $export['runner_avatar'] = $view;

  $view = new view();
  $view->name = 'runners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Runners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Runners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_donation_count' => 'field_donation_count',
    'field_total_donations' => 'field_total_donations',
    'field_campaign_count' => 'field_campaign_count',
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_runners_node']['id'] = 'reverse_field_runners_node';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['field'] = 'reverse_field_runners_node';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['label'] = 'Teams';
  /* Relationship: User: Content authored */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'users';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Active Campaign';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_avatar']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_avatar']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'profile_thumbnail',
    'image_link' => '',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Donation Count */
  $handler->display->display_options['fields']['field_donation_count']['id'] = 'field_donation_count';
  $handler->display->display_options['fields']['field_donation_count']['table'] = 'field_data_field_donation_count';
  $handler->display->display_options['fields']['field_donation_count']['field'] = 'field_donation_count';
  $handler->display->display_options['fields']['field_donation_count']['label'] = '';
  $handler->display->display_options['fields']['field_donation_count']['element_label_colon'] = FALSE;
  /* Field: Field: Total Donations */
  $handler->display->display_options['fields']['field_total_donations']['id'] = 'field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['table'] = 'field_data_field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['field'] = 'field_total_donations';
  $handler->display->display_options['fields']['field_total_donations']['label'] = '';
  $handler->display->display_options['fields']['field_total_donations']['element_label_colon'] = FALSE;
  /* Field: User: Campaign Count */
  $handler->display->display_options['fields']['field_campaign_count']['id'] = 'field_campaign_count';
  $handler->display->display_options['fields']['field_campaign_count']['table'] = 'field_data_field_campaign_count';
  $handler->display->display_options['fields']['field_campaign_count']['field'] = 'field_campaign_count';
  $handler->display->display_options['fields']['field_campaign_count']['label'] = '';
  $handler->display->display_options['fields']['field_campaign_count']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_runners_node';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'team_id';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Make this my active R2EP campaign (field_active_campaign) */
  $handler->display->display_options['filters']['field_active_campaign_value']['id'] = 'field_active_campaign_value';
  $handler->display->display_options['filters']['field_active_campaign_value']['table'] = 'field_data_field_active_campaign';
  $handler->display->display_options['filters']['field_active_campaign_value']['field'] = 'field_active_campaign_value';
  $handler->display->display_options['filters']['field_active_campaign_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_active_campaign_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Event (field_event) */
  $handler->display->display_options['filters']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['filters']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['filters']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['filters']['field_event_target_id']['relationship'] = 'reverse_field_runners_node';
  $handler->display->display_options['filters']['field_event_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_target_id']['expose']['operator_id'] = 'field_event_target_id_op';
  $handler->display->display_options['filters']['field_event_target_id']['expose']['label'] = 'Event (field_event)';
  $handler->display->display_options['filters']['field_event_target_id']['expose']['operator'] = 'field_event_target_id_op';
  $handler->display->display_options['filters']['field_event_target_id']['expose']['identifier'] = 'field_event_target_id';
  $handler->display->display_options['filters']['field_event_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'runners';
  $translatables['runners'] = array(
    t('Master'),
    t('Runners'),
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
    t('Teams'),
    t('Active Campaign'),
    t('Nid'),
    t('Event (field_event)'),
    t('Page'),
  );
  $export['runners'] = $view;

  $view = new view();
  $view->name = 'team_runners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Team Runners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our Team';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_runners_node']['id'] = 'reverse_field_runners_node';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['field'] = 'reverse_field_runners_node';
  $handler->display->display_options['relationships']['reverse_field_runners_node']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  $handler->display->display_options['sorts']['realname']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['realname']['expose']['label'] = 'Real name';
  /* Sort criterion: Field: Total Donations (field_total_donations) */
  $handler->display->display_options['sorts']['field_total_donations_value']['id'] = 'field_total_donations_value';
  $handler->display->display_options['sorts']['field_total_donations_value']['table'] = 'field_data_field_total_donations';
  $handler->display->display_options['sorts']['field_total_donations_value']['field'] = 'field_total_donations_value';
  $handler->display->display_options['sorts']['field_total_donations_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_total_donations_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_total_donations_value']['expose']['label'] = 'Total Donations';
  /* Sort criterion: Field: Donation Count (field_donation_count) */
  $handler->display->display_options['sorts']['field_donation_count_value']['id'] = 'field_donation_count_value';
  $handler->display->display_options['sorts']['field_donation_count_value']['table'] = 'field_data_field_donation_count';
  $handler->display->display_options['sorts']['field_donation_count_value']['field'] = 'field_donation_count_value';
  $handler->display->display_options['sorts']['field_donation_count_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_donation_count_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_donation_count_value']['expose']['label'] = 'Donation Count';
  /* Sort criterion: User: Campaign Count (field_campaign_count) */
  $handler->display->display_options['sorts']['field_campaign_count_value']['id'] = 'field_campaign_count_value';
  $handler->display->display_options['sorts']['field_campaign_count_value']['table'] = 'field_data_field_campaign_count';
  $handler->display->display_options['sorts']['field_campaign_count_value']['field'] = 'field_campaign_count_value';
  $handler->display->display_options['sorts']['field_campaign_count_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_campaign_count_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_campaign_count_value']['expose']['label'] = 'Campaign Count';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_runners_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['team_runners'] = array(
    t('Master'),
    t('Our Team'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing User from field_runners'),
    t('Real name'),
    t('Total Donations'),
    t('Donation Count'),
    t('Campaign Count'),
    t('All'),
    t('Block'),
  );
  $export['team_runners'] = $view;

  return $export;
}
