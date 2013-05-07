<?php

class Transaction
{
	var $input;
	var $output;
	var $succeeded;
	var $totalAmount;
	var $itemCount;
	var $realMode;
	var $firstname = "";
	var $lastname = "";
	var $peng = false;
	var $paperreceipt = false;
	var $anonymous = false;

	function Transaction($realMode)
	{
		$this->succeeded = false;
		$this->itemCount = 0;
		$this->totalAmount = 0;
		$this->realMode = $realMode;

		if($realMode)
		{
			$this->input["merchant_id"] = ""; // live key goes here
		}
		else // test mode
		{
			$this->input["merchant_id"] = "279350000"; // testing mode...

			// NOTE if you use test mode, you can only use the following CC numbers
			//
			// 4030000010001234 visa approved
			// 4003050500040005 visa declined
			// 5100000020002000 mc hold card
			// use any valid expiry
		}
	}

	function setCardInfo($name, $num, $month, $year)
	{
		$this->input["trnCardOwner"] = $name;
		$this->input["trnCardNumber"] = $num;
		$this->input["trnExpMonth"] = $month;
		$this->input["trnExpYear"] = $year;
	}

	function setContactInfo($name, $email, $phone, $line1, $line2, $city, $prov, $code, $country)
	{
		$this->input["ordName"] = $name;
		$this->input["ordEmailAddress"] = $email;
		$this->input["ordPhoneNumber"] = $phone;

		$this->input["ordAddress1"] = $line1;
		$this->input["ordAddress2"] = $line2;
		$this->input["ordCity"] = $city;
		$this->input["ordProvince"] = $prov;
		$this->input["ordPostalCode"] = $code;
		$this->input["ordCountry"] = $country;
	}

	function setPersonalInfo($fname, $lname, $peng = false, $paperreceipt = false, $anonymous = false)
	{
		$this->firstname = $fname;
		$this->lastname = $lname;
		if ($peng)
			$this->peng = true;
		if ($paperreceipt)
			$this->paperreceipt = true;
		if ($anonymous)
			$this->anonymous = true;
	}

	function addItem($sku, $quantity, $cost, $name)
	{
		$this->itemCount++;
		$this->input["prod_id_" . $this->itemCount] = $sku;
		$this->input["prod_quantity_" . $this->itemCount] = $quantity;
		$this->input["prod_name_" . $this->itemCount] = $name;
		$this->input["prod_cost_" . $this->itemCount] = number_format($cost, 2, '.', '');
		$this->totalAmount += $quantity * $cost;
	}

	function makeMonthly($comment, $amount, $firstdate=false)
	{
		$this->input["trnRecurring"] = "1";
		$this->input["rbBillingPeriod"] = "M";
		$this->input["rbBillingIncrement"] = "1";
		$this->input["trnComments"] = $comment;
		$this->totalAmount = $amount;

	    if ($firstdate)
	    {
    		$this->input["rbCharge"] = "0";
    		$this->input["rbFirstBilling"] = $firstdate;
        }
        else
            $this->input["rbCharge"] = "1";
	}

	function attemptTransaction($prefix)
	{
		$this->input["trnAmount"] = number_format($this->totalAmount, 2);
		$this->input["requestType"] = "BACKEND";
		$this->input["trnOrderNumber"] = "$prefix-" . mktime();

		$paramString = "";
		foreach($this->input as $key => $value)
		{
			$paramString .= $key . "=" . urlencode($value) . "&";
		}

		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, "https://www.beanstream.com/scripts/process_transaction.asp");
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($ch, CURLOPT_POST, true);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $paramString);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);

//		$result = false;
//		for ($i = 0; $i < 5 && $result === false; $i++)
//		{
			$result = curl_exec($ch);
//			if ($result === false)
//				sleep(2);
//		}

		if ($result !== false)
			parse_str($result, $this->output);

		if ($result === false)
		{
			$this->succeeded = false;
			$this->output['messageText'] = "Temporary error - please try again";
		}
		else if(($this->output["errorType"] == "N") && ($this->output["messageText"] == "Approved"))
		{
			$this->succeeded = true;

			// Go through item list and stuff into our own database...
			// (i don't think we ever have multiple items, but just in case...)
			if ($this->realMode && ($this->input["trnRecurring"] != "1" || $this->input["rbCharge"] == "1"))
			{

			for ($i = 1; $i <= $this->itemCount; $i++)
			{
				$qry = "SELECT id FROM donations_products WHERE sku='" . $this->input['prod_id_' . $i] . "'";
				$result = mysql_query($qry);

				// Work around earlier butchering of SKU's...
				if (mysql_num_rows($result) == 0)
				{
					$qry = "SELECT id FROM donations_products WHERE sku='" . $this->input['prod_name_' . $i] . "'";
					$result = mysql_query($qry);
				}

				// If still not found, assume new product
				if (mysql_num_rows($result) == 0)
				{
					$qry = "INSERT INTO donations_products SET sku='" . $this->input['prod_id_' . $i] . "'";
					mysql_query($qry);
					$prod_id = mysql_insert_id();
					mail("monitoring@ewb.ca", "Unknown product ID!", $qry . "\n\n" . $prod_id);
				}
				else
				{
					list($prod_id) = mysql_fetch_array($result);
				}

				// We now have a product ID; record the transaction itself

				$qry = "INSERT INTO donations SET
					firstname='" . addslashes($this->input['ordName']) . "',
					fname='" . addslashes($this->firstname) . "',
					lname='" . addslashes($this->lastname) . "',
					peng='" . $this->peng . "',
					email='" . addslashes($this->input['ordEmailAddress']) . "',
					phone='" . addslashes($this->input['ordPhoneNumber']) . "',
					address1='" . addslashes($this->input['ordAddress1']) . "',
					address2='" . addslashes($this->input['ordAddress2']) . "',
					city='" . addslashes($this->input['ordCity']) . "',
					province='" . addslashes($this->input['ordProvince']) . "',
					postalcode='" . addslashes($this->input['ordPostalCode']) . "',
					country='" . addslashes($this->input['ordCountry']) . "',
					amount='" . ($this->input['prod_cost_' . $i] * $this->input['prod_quantity_' . $i]) . "',
					product_id=" . $prod_id . ",
					cctype='" . $this->output['cardType'] . "',
					tx_id='" . $this->output['trnId'] . "',
					paperreceipt='" . $this->paperreceipt . "',
					anonymous='" . $this->anonymous . "'";
				mysql_query($qry) or die($qry . "<br/>" . mysql_error());;
				$this->output['ewbDonationId'] = mysql_insert_id();

			}

			}

		}
		else
		{
			$this->succeeded = false;
		}
	}
}
