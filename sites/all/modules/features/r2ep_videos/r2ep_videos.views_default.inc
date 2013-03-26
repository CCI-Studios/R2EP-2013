<?php
/**
 * @file
 * r2ep_videos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function r2ep_videos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-1-2';
  $handler->display->display_options['style_options']['class'] = 'gridContainer mediaList';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Youtube Link */
  $handler->display->display_options['fields']['field_youtube_link']['id'] = 'field_youtube_link';
  $handler->display->display_options['fields']['field_youtube_link']['table'] = 'field_data_field_youtube_link';
  $handler->display->display_options['fields']['field_youtube_link']['field'] = 'field_youtube_link';
  $handler->display->display_options['fields']['field_youtube_link']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_link']['alter']['text'] = '<a rel="shadowbox" href="http://www.youtube.com/embed/[field_youtube_link-video_id]?wmode=opaque">
	<!-- <img src="http://i4.ytimg.com/vi/[field_youtube_link-video_id]/0.jpg" /> -->
	<img src="/sites/default/files/styles/event_thumb/public/youtube/[field_youtube_link-video_id].png" />
	<div class="button--play"></div>
</a>
';
  $handler->display->display_options['fields']['field_youtube_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_link']['element_wrapper_class'] = 'mediaList-image';
  $handler->display->display_options['fields']['field_youtube_link']['click_sort_column'] = 'input';
  $handler->display->display_options['fields']['field_youtube_link']['type'] = 'youtube_thumbnail';
  $handler->display->display_options['fields']['field_youtube_link']['settings'] = array(
    'image_style' => 'event_thumb',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_youtube_link]';
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'video' => 'video',
  );

  /* Display: Videos 2x2 */
  $handler = $view->new_display('block', 'Videos 2x2', 'block');

  /* Display: Videos 3x1 */
  $handler = $view->new_display('block', 'Videos 3x1', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-1-3';
  $handler->display->display_options['style_options']['class'] = 'gridContainer mediaList';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['videos'] = array(
    t('Master'),
    t('Videos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a rel="shadowbox" href="http://www.youtube.com/embed/[field_youtube_link-video_id]?wmode=opaque">
	<!-- <img src="http://i4.ytimg.com/vi/[field_youtube_link-video_id]/0.jpg" /> -->
	<img src="/sites/default/files/styles/event_thumb/public/youtube/[field_youtube_link-video_id].png" />
	<div class="button--play"></div>
</a>
'),
    t('Videos 2x2'),
    t('Videos 3x1'),
  );
  $export['videos'] = $view;

  return $export;
}
