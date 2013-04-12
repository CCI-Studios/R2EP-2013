<?php

function _r2ep_view_campaign() {
	$node = menu_get_object();
	$nid = $node->nid;
	return l(t('View Campaigns'), "campaigns/$nid", array('attributes' => array('class' => array('btn', 'btn--block'))));
}