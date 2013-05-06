(function ($) {
	$(function() {
		$('ul.menu ul').show();
		$('ul.menu ul').hide();

		$('ul.menu li').hover(function() {
			clearTimeout($.data(this, 'timer'));
			$(this).parent().find('ul').slideUp(100);
			$('ul', this).stop(true, true).slideDown(100);
		}, function() {
			$.data(this, 'timer', setTimeout($.proxy(function() {
				$('ul', this).stop(true, true).slideUp(100);
			}, this), 300));
		});
	});
}(jQuery));