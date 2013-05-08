<?php

class TeamMigration extends Migration {

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
		$this->description = t('Migrate teams from the old site');

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'id' => array(
					'type' => 'int',
					'not null' => true,
					'alias' => 't',
				),
			),
			MigrateDestinationNode::getKeySchema()
		);

		$query = Database::getConnection('default', 'r2ep')
			->select('goo_teams', 't');
		$query->fields('t', array('id', 'name', 'description',));

		$query->leftJoin('goo_campaigns_team', 'ct', '(ct.teamid = t.id)');
		$query->leftJoin('goo_campaigns', 'c', '(c.campaignid=ct.campaignid)');
		$query->leftJoin('goo_metacampaign', 'm', '(m.id = c.metacampaign)');

		$query->addExpression('GROUP_CONCAT(c.userid)', 'runners');
		$query->addExpression('MAX(c.metacampaign)', 'event');
		$query->condition('m.domain', 'r2ep.ewb.ca');
		$query->condition('t.visible', '1');
		$query->condition('t.locked', '0');

		$query->groupBy('t.id');

		$this->source = new MigrateSourceSQL($query);
		$this->destination = new MigrateDestinationNode('team');


		$this->addFieldMapping('title', 'name');
		$this->addFieldMapping('uid')
			->sourceMigration('User');
		$this->addFieldMapping('status')->defaultValue(1);
		$this->addFieldMapping('field_description', 'description');
		$this->addFieldMapping('field_description:language')->defaultValue('en');

		$this->addFieldMapping('field_runners', 'runners')
			->separator(',')
			->sourceMigration('User');
		$this->addFieldMapping('field_event', 'event');

		$this->addUnmigratedSources(array(

		));

		$this->addUnmigratedDestinations(array(
			'created', 'changed', 'promote', 'sticky', 'revision',
			'log', 'language', 'tnid', 'translate', 'revision_uid', 'is_new',
			'path', 'comment', 'pathauto',

			'field_avatar', 'field_avatar:file_class', 'field_avatar:language',
			'field_avatar:destination_dir', 'field_avatar:destination_file',
			'field_avatar:file_replace', 'field_avatar:preserve_files',
			'field_avatar:source_dir', 'field_avatar:alt', 'field_avatar:title',

			'field_total_donations', 'field_donation_count', 'field_total_goal',
		));

	}

	public function prepareRow($row) {
		$query = Database::getConnection('default', 'r2ep')
			->select('goo_campaigns_team', 'ct');
		$query->addField('c', 'userid');
		$query->leftJoin('goo_campaigns', 'c', '(c.campaignid=ct.campaignid)');
		$query->condition('ct.teamid', $row->id);
		$query->condition('ct.is_admin', 1);

		$row->uid = $query->execute()->fetchField();

		$row->event = $this->event_map[$row->event];
	}

}