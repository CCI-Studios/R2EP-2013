(function ($) {
	$(function() {
		$('[data-object=countdown]').each(function() {
			var $this = $(this),
				date = $this.data('date'),
				amount = parseInt($this.data('amount'), 10),
				$days = $this.find('.days'),
				$hours = $this.find('.hours'),
				$minutes = $this.find('.minutes'),
				$seconds = $this.find('.seconds')
				increment = 1;

			var tick = function() {
				date -= amount;

				var days = Math.floor(date/(60*60*24)),
					hours = Math.floor((date - days*60*60*24)/ (60*60)),
					minutes = Math.floor((date - days*60*60*24 - hours*60*60)/ (60)),
					seconds = Math.floor(date - days*60*60*24 - hours*60*60 - minutes*60);

				$days.find('.darkBlock').html(days * amount);
				$hours.find('.darkBlock').html(hours);
				$minutes.find('.darkBlock').html(minutes);
				$seconds.find('.darkBlock').html(seconds);


				if (date > 0) {
					setTimeout(tick, 1000);
				}
			}

			setTimeout(tick, 1000);
		});
	});
}(jQuery));