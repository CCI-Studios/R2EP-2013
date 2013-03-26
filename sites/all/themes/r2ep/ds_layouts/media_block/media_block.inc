<?php

function ds_media_block() {
	return array(
		'label'		=> t('Media Block Layout'),
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