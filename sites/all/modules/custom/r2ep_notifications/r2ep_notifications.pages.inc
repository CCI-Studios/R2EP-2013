<?php

function r2ep_notifications_delete_function($node) {
	// Taken from node modules node_delete_confirm submit handler
	node_delete($node->nid);
	watchdog('content', '@type: deleted %title.', array('@type' => $node->type, '%title' => $node->title));
	// Do a drupal goto here to preserver the 'destination' parameter
	drupal_goto();
}