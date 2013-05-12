<?php
/**
 * @file
 * r2ep_videos.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function r2ep_videos_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_short_description'
  $field_bases['field_short_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_short_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_youtube_link'
  $field_bases['field_youtube_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_youtube_link',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'video_id' => array(
        0 => 'video_id',
      ),
    ),
    'locked' => 0,
    'module' => 'youtube',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'youtube',
  );

  return $field_bases;
}
