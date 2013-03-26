<?php
/**
 * @file
 * r2ep_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function r2ep_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function r2ep_events_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function r2ep_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
