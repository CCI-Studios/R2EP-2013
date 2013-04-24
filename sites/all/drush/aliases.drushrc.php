<?php

$aliases['dev'] = array(
	'uri' => 'r2ep.ccistaging.com',
	'root' => '/home/staging/subdomains/r2ep/public_html',
	'remote-host' => 'ccistaging.com',
	'remote-user' => 'staging',

	'path-aliases' => array(
		'%dump-dir' => '/home/staging/subdomains/r2ep/_dumps',
		'%files'	=> 'sites/default/files',
	),

	'ssh-options' => "-p 37241",
);

$aliases['live'] =  array(
	'uri' => 'www.r2eptest.ewb.ca',
	'root' => '/var/www/sites/r2ep',
	'remote-host' => 'accra.ewb.ca',
	'remote-user' => 'r2ep',

	'path-aliases' => array(
		'%dump-dir' => '/var/www/sites/r2ep/_dumps',
		'%files'	=> 'sites/default/files',
	),
);