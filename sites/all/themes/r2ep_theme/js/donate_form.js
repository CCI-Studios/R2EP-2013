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
			page = 0,
			timer = null,
			delay = 500,

			searchScan = function () {
				var $result = $('.webform-client-form');
				if ($result.length) {
					// new found node !== old node
					if ($body == null || $result.get(0) !== $body.get(0)) {
						setup();
					}
					found = true;

					timer = setTimeout(searchScan, delay);
				} else {
					page = 0;
					found = false;
					timer = setTimeout(searchScan, delay);
				}
			},

			setup = function() {
				$body = $('.webform-client-form');
				$content = $body.find('> div');
				$amount1 = $body.find('input[name="0[0]"]');
				$amount2 = $body.find('input[name="wfbs_set_price"]');
				$monthly1 = $body.find('input[name="1"]');
				$monthly2 = $body.find('input[name="wfbs_reoccuring"]');
				$pages = $body.find('.pages');
				$prevLinks = $body.find('.prevButton');
				$nextLinks = $body.find('.nextButton');

				$nameFields = $body.find('input[name="wfbs_first_name"], input[name="wfbs_last_name"]');
				$addressField = $body.find('input[name="wfbs_address1"]');
				$cityField = $body.find('input[name="wfbs_city"]');
				$postalField = $body.find('input[name="wfbs_postal"]');
				$provinceField = $body.find('input[name="wfbs_province"]');
				$phoneField = $body.find('input[name="wfbs_phone"]');
				$emailField = $body.find('input[name="wfbs_email"]');
				$typeField = $body.find('#edit-wfbs-card-type');
				$messageField = $body.find('#edit-0-pages-page1-0');
				$cardField = $body.find('#edit-wfbs-card-number');
				$cardField.keypress(function() {
					$cardField.validateCreditCard(function(result) {
						if (result.luhn_valid) {
							$cardField.removeClass('error');
						} else {
							$cardField.addClass('error');
						}
					});
				});

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

				$prevLinks.click(function() {
					var $this = $(this)
						index = $prevLinks.index($this);

					if (page > 0) {
						page--;
					}

					$pages.children(0).animate({
						'margin-left': (-100*page + '%')
					});
				});

				$nextLinks.click( function() {
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

				$body.submit(function(event) {
					if (page == 2) {
						clearTimeout(timer);
						page = 0;
						found = false;
						timer = setTimeout(searchScan, delay*4);
					} else {
						$nextLinks.eq(page).click();
						event.preventDefault(); // cancel submit
						event.stopPropagation();
						return false;
					}
				});

				$body.data('events').submit.reverse(); // run me first FIXME: hack

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

		timer = searchScan();
	});
}(jQuery));