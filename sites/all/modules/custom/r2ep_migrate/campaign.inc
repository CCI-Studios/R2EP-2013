<?php

class CampaignMigration extends Migration {

	private $event_map = array(
		'33' => '194', // saskatchewan
		'29' => '190', // okanagan college
		'19' => '199', // oktoberfest run
		'36' => '197', // canadian derby edmonton
		'34' => '195', // manitoba marathon
		'45' => '205', // national bank charity
		'32' => '193', // scotiabank calgary
		'30' => '191', // scotia blue nose
		'47' => '207', // scotiabank
		// '' => '204', // organized by EWB
		'35' => '196', // tely 10 mile
		'37' => '198', // tour du mont-royal
		'31' => '192', // ottawa fall colours
		'40' => '200', // scotiabank toronto
		'41' => '201', // kingston
		'43' => '202', // hamilton
		'42' => '203', // london
		'46' => '206', // fredericton
	);

	public function __construct() {
		parent::__construct();
		$this->description = t('Migrate Users from the old site');

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'campaignid' => array(
					'type' => 'int',
					'not null' => true,
					'alias' => 'c'
				),
			),
			MigrateDestinationNode::getKeySchema()
		);

		$query = Database::getConnection('default', 'r2ep')
			->select('goo_campaigns', 'c');
		$query->fields('c', array('campaignid', 'userid', 'shortname', 'cellphone', 'metacampaign', 'state',));
		$query->leftJoin('goo_campaigns_look', 'l', '(l.campaignid = c.campaignid)');
		$query->leftJoin('goo_metacampaign', 'm', '(m.id = c.metacampaign)');
		$query->condition('m.domain', 'r2ep.ewb.ca');
		$query->fields('l', array('title', 'goal', 'textbody',));

		$this->source = new MigrateSourceSQL($query);
		$this->destination = new MigrateDestinationNode('campaign');

		$this->addFieldMapping('title', 'title');
		$this->addFieldMapping('uid', 'userid')
			->sourceMigration('User');
		$this->addFieldMapping('status')->defaultValue(1);
		$this->addFieldMapping('body', 'textbody');
		$this->addFieldMapping('body:summary');
		$this->addFieldMapping('body:format')->defaultValue('filtered_html');
		$this->addFieldMapping('body:language')->defaultValue('en');
		$this->addFieldMapping('field_donation_form')->defaultValue(150);
		$this->addFieldMapping('field_goal', 'goal');
		$this->addFieldMapping('field_event', 'metacampaign');

		$this->addUnmigratedSources(array(
		));

		$this->addUnmigratedDestinations(array(
			'created', 'changed', 'promote', 'sticky', 'revision',
			'log', 'language', 'tnid', 'translate', 'revision_uid', 'is_new',
			'path', 'comment', 'pathauto',

			'field_total_donations', 'field_donation_count', 'field_youtube_link',
			'field_active_campaign',
		));

	}

	function prepareRow($row) {

		$row->metacampaign = $this->event_map[$row->metacampaign];

	}

}