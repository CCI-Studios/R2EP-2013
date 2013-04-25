(function ($) {
	$.fn.increment = function (from, to, duration) {
	    var self = this;
	    $({number: from}).animate({number: to}, {
	        duration: duration,
	        easing: 'swing',
	        step: function () {
	            self.text(Math.ceil(this.number));
	        }
	    });
	};

	$(function () {
		var duration = 3000,
			counters = $('[data-object=counter]');

		counters.each(function () {
			var $this = $(this),
				start = $this.data('start'),
				end = $this.data('end');
				parent = $this.parent();

			parent.prepend('$');
			$this.increment(start, end, 3000);
		})
	});
}(jQuery));