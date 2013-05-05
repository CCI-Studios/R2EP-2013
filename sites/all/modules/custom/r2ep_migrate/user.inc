<?php

class UserMigration extends Migration {


	public function __construct() {
		parent::__construct();
		$this->description = t('Migrate Users from the old site');

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'userid' => array(
					'type' => 'int',
					'not null' => true,
				),
			),
			MigrateDestinationUser::getKeySchema()
		);

		$query = Database::getConnection('default', 'r2ep')
			->select('goo_users', 'u');
		$query->fields('u', array('userid', 'email', 'firstname',
			'lastname', 'password', 'isadmin',));

		$this->source = new MigrateSourceSQL($query);
		$this->destination = new MigrateDestinationUser();

		$this->addFieldMapping('mail', 'email');
		$this->addFieldMapping('pass', 'password');
		$this->addFieldMapping('name', 'email')->dedupe('users', 'name');
		$this->addFieldMapping('status')->defaultValue('1');
		$this->addFieldMapping('role_names', 'roles');

		$this->addFieldMapping('field_first_name', 'firstname');
		$this->addFieldMapping('field_first_name:language')->defaultValue('en');
		$this->addFieldMapping('field_last_name', 'lastname');
		$this->addFieldMapping('field_last_name:language')->defaultValue('en');

		$this->addUnmigratedSources(array(
			'isadmin'
		));

		$this->addUnmigratedDestinations(array(
			'created', 'access', 'login', 'roles', 'picture',
			'signature', 'signature_format', 'timezone', 'language',
			'theme', 'init', 'data', 'is_new',

			'field_avatar', 'field_avatar:file_class', 'field_avatar:language',
			'field_avatar:destination_dir', 'field_avatar:destination_file', 'field_avatar:file_replace',
			'field_avatar:preserve_files', 'field_avatar:source_dir', 'field_avatar:alt', 'field_avatar:title',

			'field_description', 'field_description:format', 'field_description:language',

			'field_total_donations', 'field_donation_count', 'field_campaign_count',
			'field_total_goal', 'field_gender', 'field_cell_number', 'field_cell_number:language',
			'path', 'pathauto'
		));

	}

	public function prepareRow($row) {
		$row->roles = array('authenticated user');

		if ($row->isadmin) {
			$row->roles[] = 'editor';
		}
	}

}