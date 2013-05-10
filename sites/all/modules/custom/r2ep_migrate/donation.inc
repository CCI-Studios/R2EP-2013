<?php

class DonationMigration extends Migration {


	public function __construct() {
		parent::__construct();
		$this->description = t('Migrate donations from the old site');

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'donationid' => array(
					'type' => 'int',
					'not null' => true,
				),
			),
			MigrateDestinationNode::getKeySchema()
		);

		$query = Database::getConnection('default', 'r2ep')
			->select('goo_donations', 'd')
			->orderBy('d.donationid');
		$query->fields('d', array('donationid', 'campaignid', 'donationamount', 'monthly', 'donationmessage', 'displayonpage', 'displayanonymously', 'datedonated', 'txid', 'txnumber', 'firstname', 'lastname', 'email', 'userid', 'preferredlanguage', 'fullyanonymous', 'donationtype', 'manualtransactionid', 'hiddenbycampaigner', 'contactid', ));

		$query->leftJoin('goo_campaigns', 'c', 'c.campaignid = d.campaignid');
		$query->leftJoin('goo_metacampaign', 'm', 'm.id = c.metacampaign');
		$query->condition('m.domain', 'r2ep.ewb.ca');

		$this->source = new MigrateSourceSQL($query);
		$this->destination = new MigrateDestinationNode('donation');

		$this->addFieldMapping('status')->defaultValue(1);
		$this->addFieldMapping('promote')->defaultValue(0);
		$this->addFieldMapping('sticky')->defaultValue(0);
		$this->addFieldMapping('created', 'datedonated');

		$this->addFieldMapping('field_first_name', 'firstname');
		$this->addFieldMapping('field_first_name:language')->defaultValue('en');
		$this->addFieldMapping('field_last_name', 'lastname');
		$this->addFieldMapping('field_last_name:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_phone');
		$this->addFieldMapping('field_contact_phone:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_email', 'email');
		$this->addFieldMapping('field_contact_address1');
		$this->addFieldMapping('field_contact_address1:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_address2');
		$this->addFieldMapping('field_contact_address2:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_city');
		$this->addFieldMapping('field_contact_city:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_province');
		$this->addFieldMapping('field_contact_province:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_postal');
		$this->addFieldMapping('field_contact_postal:language')->defaultValue('en');
		$this->addFieldMapping('field_contact_country');
		$this->addFieldMapping('field_contact_country:language')->defaultValue('en');
		$this->addFieldMapping('field_description', 'donationmessage');
		$this->addFieldMapping('field_description:language')->defaultValue('en');

		$this->addFieldMapping('field_wfbs_price', 'donationamount');
		$this->addFieldMapping('field_campaign', 'campaignid')
			->sourceMigration('Campaign');
		$this->addFieldMapping('field_team');
		$this->addFieldMapping('field_event');


		$this->addUnmigratedSources(array(
			'userid', 'preferredlanguage', 'fullyanonymous', 'donationtype', 'manualtransactionid',
			'hiddenbycampaigner', 'contactid',
			'monthly', 'donationmessage', 'displayonpage', 'displayanonymously', 'txid', 'txnumber'
		));

		$this->addUnmigratedDestinations(array(
			'revision', 'log', 'language', 'is_new',
			'tnid', 'translate', 'revision_uid', 'path', 'comment', 'pathauto',

			'title', 'uid', 'changed',

			'field_avatar', 'field_avatar:file_class', 'field_avatar:language', 'field_avatar:destination_dir',
			'field_avatar:destination_file', 'field_avatar:file_replace', 'field_avatar:preserve_files',
			'field_avatar:source_dir', 'field_avatar:alt', 'field_avatar:title',
		));
	}

	function prepateRow($row) {
		$row->datedonated = strtotime($row->datedonated);
	}

}