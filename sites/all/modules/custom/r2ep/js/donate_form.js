(function ($) {
	$(function() {
		var $body = null,
			$content = null;
			$amount1 = null,
			$amount2 = null,
			$monthly1 = null,
			$monthly2 = null,
			$prevLinks = null,
			$nextLinks = null,
			$pages = null,
			$nameFields = null,
			$cardField = null,
			$addressField = null,
			$cityField = null,
			$provinceField = null,
			$countryField = null,

			found = false,
			page = 0;

			searchScan = function () {
				if ($('.webform-client-form').length) {

					if (!found) {
						setup();
					}
					found = true;

				} else {
					setTimeout(searchScan, 1500);
				}
			},

			setup = function() {
				$body = $('.webform-client-form');
				$content = $body.find('> div');
				$amount1 = $body.find('input[name="1"]');
				$amount2 = $body.find('input[name="wfbs_set_price"]');
				$monthly1 = $body.find('input[name="2"]');
				$monthly2 = $body.find('input[name="wfbs_reoccuring"]');
				$pages = $body.find('.pages');
				$prevLinks = $body.find('.prevButton');
				$nextLinks = $body.find('.nextButton');
				$nameFields = $body.find('input[name="wfbs_first_name"], input[name="wfbs_last_name"]');
				$cardField = $body.find('input[name="wfbs_card_number"]');
				$addressField = $body.find('input[name="wfbs_address1"]');
				$cityField = $body.find('input[name="wfbs_city"]');
				$provinceField = $body.find('input[name="wfbs_province"]');
				$countryField = $body.find('input[name="wfbs_country"]');

				$namePreview = $body.find('.namePreview');
				$moneyPreview = $body.find('.moneyPreview');
				$addressPreview = $body.find('.addressPreview');
				$cardPreview = $body.find('.cardPreview');

				$amount1.change(function() {
					var value = $amount1.filter(':checked').val();
					$amount2.filter('[value='+ value +']').attr('checked', true);
					$moneyPreview.text('$'+ value +' '+ ($monthly1.filter(':checked').val()? 'Monthly' : ''));
				});
				$amount2.change(function() {
					var value = $amount2.filter(':checked').val();
					$amount1.filter('[value='+ value +']').attr('checked', true);
					$moneyPreview.text('$'+ value + ($monthly1.filter(':checked').val()? 'Monthly' : ''));
				});

				$monthly1.change(function() {
					var value = $monthly1.filter(':checked').val();
					$monthly2.filter('[value='+ value +']').attr('checked', true);
				});
				$monthly2.change(function() {
					var value = $monthly2.filter(':checked').val();
					$monthly1.filter('[value='+ value +']').attr('checked', true);
				});

				$($addressField, $cityField, $provinceField, $countryField).bind('keyup input paste', function() {
					$addressPreview.html(
						$addressField.val() +'<br/>'+
						$cityField.val() + ', ' + $provinceField.val() +'<br/>'+
						$countryField.val()
					);
				});

				$nameFields.bind('keyup input paste', function() {
					var name = '';
					$nameFields.each(function() {
						name += $(this).val() + ' ';
					});
					name = name.trim();
					$namePreview.text(name);
				});

				$prevLinks.click(function() {
					var $this = $(this)
						index = $prevLinks.index($this);

					if (index > 0) {
						index--;
					}

					$pages.children(0).animate({
						'margin-left': -705*index
					});
				});

				$nextLinks.click(function() {
					var $this = $(this)
						index = $nextLinks.index($this);

					if (index < 2) {
						index++;
					}

					$pages.children(0).animate({
						'margin-left': -705*index
					});
				});
			};

		searchScan();
	});
}(jQuery));