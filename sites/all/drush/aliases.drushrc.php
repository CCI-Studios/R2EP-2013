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