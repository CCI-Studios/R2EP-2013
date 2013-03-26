<?php

class wf_beanstream_transaction {
	var $input;
	var $output;
	var $succeeded;
	var $totalAmount;
	var $itemCount;
	var $realMode;
	var $firstname = '';
	var $lastname = '';
	var $peng = false;
	var $paperreceipt = false;
	var $anonymous = false;

	function __construct($key = null) {
		$this->succeeded = false;
		$this->itemCount = 0;
		$this->totalAmount = 0;
		$this->realMode = isset($key);

		if ($this->realMode) {
			$this->input['merchant_id'] = $key;
		} else {
			$this->input['merchant_id'] = '279350000';

			// NOTE if you use test mode, you can only use the following CC numbers
			//
			// 4030000010001234 visa approved
			// 4003050500040005 visa declined
			// 5100000020002000 mc hold card
			// use any valid expiry
		}
	}

	function setCardInfo($name, $num, $month, $year) {
		$this->input['trnCardOwner'] = $name;
		$this->input['trnCardNumber'] = $num;
		$this->input['trnExpMonth'] = $month;
		$this->input['trnExpYear'] = $year;
	}

	function setContactInfo($name, $email, $phone, $line1, $line2, $city, $prov, $code, $country) {
		$this->input['ordName'] = $name;
		$this->input['ordEmailAddress'] = $email;
		$this->input['ordPhoneNumber'] = $phone;

		$this->input['ordAddress1'] = $line1;
		$this->input['ordAddress2'] = $line2;
		$this->input['ordCity'] = $city;
		$this->input['ordProvince'] = $prov;
		$this->input['ordPostalCode'] = $code;
		$this->input['ordCountry'] = $country;
	}

	function setPersonalInfo($fname, $lname, $peng = false, $paperreceipt = false, $anonymous = false) {
		$this->firstname = $fname;
		$this->lastname = $lname;

		$this->peng = $peng;
		$this->paperreceipt = $paperreceipt;
		$this->anonymous = $anonymous;
	}


}