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

	function addItem($sku, $quantity, $cost, $name) {
		$this->itemCount++;
		$cost = floatval($cost); // Note: Bad for many joined transactions, not a concern for this application

		$this->input['prod_id_'. $this->itemCount] = $sku;
		$this->input['prod_quantity_'. $this->itemCount] = $quantity;
		$this->input['prod_name_'. $this->itemCount] = $name;
		$this->input['prod_cost_'. $this->itemCount] = number_format($cost, 2, '.', '');
		$this->totalAmount += $quantity * $cost;
	}

	function makeMonthly($comment, $amount, $firstdate = false) {
		$this->input['trnRecurring'] = '1';
		$this->input['rbBillingPeriod'] = 'M';
		$this->input['rbBillingIncrement'] = '1';
		$this->input['trnComments'] = $comment;
		$this->totalAmount = $amount;

		if ($firstdate) {
			$this->input['rbCharge'] = '0';
			$this->input['rbFirstBilling'] = $firstdate;
		} else {
			$this->input['rbCharge'] = '1';
		}
	}

	function attemptTransaction($prefix) {
		$this->input['trnAmount'] = number_format($this->totalAmount, 2);
		$this->input['requestType'] = 'BACKEND';
		$this->input['trnOrderNumber'] = $prefix .'-'. mktime();

		$params = "";
		foreach ($this->input as $key => $value) {
			$params .= $key .'='. urlencode($value) .'&';
		}

		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, "https://www.beanstream.com/scripts/process_transaction.asp");
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($ch, CURLOPT_POST, true);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $params);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
		$result = curl_exec($ch);

		if ($result !== false) {
			parse_str($result, $this->output);
		}

		if ($result == false) {
			$this->succeeded = false;
			$this->output['messageText'] = "Temporary error - please try again";
		} else if ($this->output['errorType'] == 'N' && $this->output['messageText'] == 'Approved') {
			$this->succeeded = true;
		}

		return $this->succeeded;
	}
}