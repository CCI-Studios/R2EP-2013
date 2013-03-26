<?php
/**
 * @file
 * r2ep_featured_people.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function r2ep_featured_people_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function r2ep_featured_people_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function r2ep_featured_people_node_info() {
  $items = array(
    'featured_person' => array(
      'name' => t('Featured Person'),
      'base' => 'node_content',
      'description' => t('Featured People show up in the tabbed section'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
