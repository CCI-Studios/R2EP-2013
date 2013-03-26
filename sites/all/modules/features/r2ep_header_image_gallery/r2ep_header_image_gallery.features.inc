<?php
/**
 * @file
 * r2ep_header_image_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function r2ep_header_image_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function r2ep_header_image_gallery_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function r2ep_header_image_gallery_node_info() {
  $items = array(
    'header_image' => array(
      'name' => t('Header Image'),
      'base' => 'node_content',
      'description' => t('An image and description for use in the header'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
