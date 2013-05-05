<?php

class TeamMigration extends Migration {

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
		$query->addExpression('GROUP_CONCAT(c.userid)', 'runners');
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
		$this->addFieldMapping('field_event')->defaultValue('404'); // FIXME

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
	}


}