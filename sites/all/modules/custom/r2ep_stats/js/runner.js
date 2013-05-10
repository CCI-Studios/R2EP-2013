(function($) {
	$(function() {
		var width = 220,
			runnerWidth = 55,
			duration = 3,
			runners = $('[data-object=runner]');

		runners.each(function() {
			var $this = $(this),
				percent = Math.min($this.data('percent'), 100),
				target = (width - runnerWidth) * percent / 100.0;

			$this.animate({
				left: target
			}, 3000);

		});
	});
}(jQuery));