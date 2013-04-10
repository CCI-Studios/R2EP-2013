<?php
/**
 * @file
 * r2ep_runners.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function r2ep_runners_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_campaign_count'
  $field_bases['field_campaign_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_campaign_count',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'computed_field',
    'settings' => array(
      'code' => '$entity_field[0][\'value\'] = "";',
      'database' => array(
        'data_default' => '',
        'data_index' => 0,
        'data_length' => 32,
        'data_not_NULL' => 0,
        'data_precision' => 10,
        'data_scale' => 2,
        'data_size' => 'normal',
        'data_type' => 'int',
      ),
      'display_format' => '$display_output = $entity_field_item[\'value\'] .\' Campaigns\';',
      'store' => 1,
    ),
    'translatable' => 0,
    'type' => 'computed',
  );

  return $field_bases;
}
