<?php

function ds_media_block_right() {
	return array(
		'label'		=> t('Media Block Right Layout'),
		'regions'	=> array(
			'header'	=> t('Header'),
			'media'		=> t('Media'),
			'body'		=> t('Body'),
			'footer'	=> t('Footer'),
		),
		//'css' => true,
		//'image' => true,
	);
}