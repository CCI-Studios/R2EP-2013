<?php
/**
 * @file
 * r2ep_conditional_donate.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_conditional_donate_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conditional_donate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conditional Donate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Donation Form */
  $handler->display->display_options['fields']['field_donation_form']['id'] = 'field_donation_form';
  $handler->display->display_options['fields']['field_donation_form']['table'] = 'field_data_field_donation_form';
  $handler->display->display_options['fields']['field_donation_form']['field'] = 'field_donation_form';
  $handler->display->display_options['fields']['field_donation_form']['label'] = '';
  $handler->display->display_options['fields']['field_donation_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_donation_form']['alter']['text'] = 'Donate';
  $handler->display->display_options['fields']['field_donation_form']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_donation_form']['alter']['path'] = 'modal_forms/nojs/webform/[field_donation_form-target_id]?cid=[nid]';
  $handler->display->display_options['fields']['field_donation_form']['alter']['link_class'] = 'btn btn--block ctools-use-modal ctools-modal-modal-popup-large';
  $handler->display->display_options['fields']['field_donation_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_donation_form']['settings'] = array(
    'link' => 1,
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

  /* Display: Campaign Donation Button */
  $handler = $view->new_display('block', 'Campaign Donation Button', 'block');
  $translatables['conditional_donate'] = array(
    t('Master'),
    t('Donate'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Campaign Donation Button'),
  );
  $export['conditional_donate'] = $view;

  return $export;
}
