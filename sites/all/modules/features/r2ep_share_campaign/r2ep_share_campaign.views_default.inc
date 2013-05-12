<?php
/**
 * @file
 * r2ep_share_campaign.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_share_campaign_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'share_campaign';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Share Campaign';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Share Campaign';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own campaign_contact content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Upload your contacts to the address book below. You can then send emails to your contacts inviting them to check out your campaign page, reminding them to donate, and thanking them when they do. You can customize all messages that you send through the system.

Click here to <a href="/node/add/campaign-contact?field_campaign=%1">add a new address</a>.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_campaign_target_id']['id'] = 'field_campaign_target_id';
  $handler->display->display_options['relationships']['field_campaign_target_id']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['relationships']['field_campaign_target_id']['field'] = 'field_campaign_target_id';
  $handler->display->display_options['relationships']['field_campaign_target_id']['label'] = 'Campaign';
  $handler->display->display_options['relationships']['field_campaign_target_id']['required'] = TRUE;
  /* Field: Global: Send e-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['label'] = '';
  $handler->display->display_options['fields']['views_send']['element_label_colon'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_contact_target_id';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_ref_contact_target_id';
  /* Field: Content: Contact Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'field_ref_contact_target_id';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_contact_email']['type'] = 'email_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Campaign (field_campaign) */
  $handler->display->display_options['arguments']['field_campaign_target_id']['id'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['arguments']['field_campaign_target_id']['field'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_action'] = 'not found';
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
    'campaign_contact' => 'campaign_contact',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'share/%';
  $translatables['share_campaign'] = array(
    t('Master'),
    t('Share Campaign'),
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
    t('Upload your contacts to the address book below. You can then send emails to your contacts inviting them to check out your campaign page, reminding them to donate, and thanking them when they do. You can customize all messages that you send through the system.

Click here to <a href="/node/add/campaign-contact?field_campaign=%1">add a new address</a>.'),
    t('Campaign'),
    t('First Name'),
    t('Last Name'),
    t('Email'),
    t('Edit'),
    t('Delete'),
    t('All'),
    t('Page'),
  );
  $export['share_campaign'] = $view;

  return $export;
}
