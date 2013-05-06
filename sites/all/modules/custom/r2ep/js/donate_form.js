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

			$namePreview = null,
			$addressPreview = null,
			$cityPreview = null,
			$postalPreview = null,
			$provincePreview = null,
			$phonePreview = null,
			$emailPreview = null,
			$moneyPreview = null,
			$typePreview = null,
			$messagePreview = null,

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
				$amount1 = $body.find('input[name="0"]');
				$amount2 = $body.find('input[name="wfbs_set_price"]');
				$monthly1 = $body.find('input[name="1"]');
				$monthly2 = $body.find('input[name="wfbs_reoccuring"]');
				$pages = $body.find('.pages');
				$prevLinks = $body.find('.prevButton');
				$nextLinks = $body.find('.nextButton');
				console.log($amount1);

				$nameFields = $body.find('input[name="wfbs_first_name"], input[name="wfbs_last_name"]');
				$addressField = $body.find('input[name="wfbs_address1"]');
				$cityField = $body.find('input[name="wfbs_city"]');
				$postalField = $body.find('input[name="wfbs_postal"]');
				$provinceField = $body.find('input[name="wfbs_province"]');
				$phoneField = $body.find('input[name="wfbs_phone"]');
				$emailField = $body.find('input[name="wfbs_email"]');
				$typeField = $body.find('#edit-wfbs-card-type');
				$messageField = $body.find('#edit-0-pages-page1-0');

				$namePreview = $body.find('.namePreview');
				$addressPreview = $body.find('.addressPreview');
				$cityPreview = $body.find('.cityPreview');
				$postalPreview = $body.find('.postalPreview');
				$provincePreview = $body.find('.provincePreview');
				$phonePreview = $body.find('.phonePreview');
				$emailPreview = $body.find('.emailPreview');
				$moneyPreview = $body.find('.donationPreview');
				$typePreview = $body.find('.typePreview');
				$messagePreview = $body.find('.messagePreview');


				$amount1.change(function() {
					var value = $amount1.filter(':checked').val();
					$amount2.filter('[value='+ value +']').attr('checked', true);
				});
				$amount2.change(function() {
					var value = $amount2.filter(':checked').val();
					$amount1.filter('[value='+ value +']').attr('checked', true);
				});

				$monthly1.change(function() {
					var value = $monthly1.filter(':checked').val();
					$monthly2.filter('[value='+ value +']').attr('checked', true);
				});
				$monthly2.change(function() {
					var value = $monthly2.filter(':checked').val();
					$monthly1.filter('[value='+ value +']').attr('checked', true);
				});

				$nameFields.bind('keyup input paste', function() {
					var name = '';
					$nameFields.each(function() {
						name += $(this).val() + ' ';
					});
					name = name.trim();
					$namePreview.text(name);
				});

				$(document).delegate('#modalContent .prevButton', 'click', function() {
					var $this = $(this)
						index = $prevLinks.index($this);

					if (page > 0) {
						page--;
					}

					$pages.children(0).animate({
						'margin-left': (-100*page + '%')
					});
				});

				$(document).delegate('#modalContent .nextButton', 'click', function() {
					var $this = $(this)
						index = $nextLinks.index($this);

					if (page < 2) {
						page++;
					}

					if (page == 2) {
						updatePreview();
					}

					$pages.children(0).animate({
						'margin-left': (-100*page + '%')
					});
				});

				var updatePreview = function() {
					$namePreview.text($nameFields.map(function(index, el) {
						return $(el).val();
					}).get().join(' '));
					$addressPreview.text($addressField.val());
					$cityPreview.text($cityField.val());
					$postalPreview.text($postalField.val());
					$provincePreview.text($provinceField.val());
					$phonePreview.text($phoneField.val());
					$emailPreview.text($emailField.val());
					$moneyPreview.text('$' + $amount1.filter(':checked').val());
					$typePreview.text($typeField.val());
					$messagePreview.text($messageField.val());
				};
			};

		searchScan();
	});
}(jQuery));