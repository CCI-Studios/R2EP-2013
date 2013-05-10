(function ($) {
	$.fn.increment = function (from, to, duration) {
	    var self = this,
	    	rx = /(\d+)(\d{3})/;
	    $({number: from}).animate({number: to}, {
	        duration: duration,
	        easing: 'swing',
	        step: function () {
	        	var s = String(Math.ceil(this.number)).replace(/^\d+/, function(w){
        			while(rx.test(w)){
            			w= w.replace(rx, '$1,$2');
        			}
        			return w;
    			});

	            self.text(s);
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