// edit-canned-message
// edit-body-und-0-value

(function($) {
	var messages = {
		'Belief in Possibility': "<p>I believe in possibility. This is why I run. Because years from now,	\
			I can see a world without poverty and it is a world I am excited about. This year, I am hitting \
			the ground running in a bright orange shirt alongside hundreds across Canada. We are running to \
			unlock potential, to challenge systems and to make an impact. My run supports the work of Engineers \
			Without Borders Canada (EWB) and its approach to change.</p> \
			Like EWBers across the country, I believe a better world is possible. <strong>Join me in believing in change \
			and support my campaign</strong> because the systems that contribute to poverty in Africa are being challenged \
			by EWB and its partners.</p>",
		'Running for Change': "<p>I'm running because I believe that change is possible.</p> \
			<p>Because the systems that contribute to poverty in Africa are being challenged every day by entrepreneurs, \
			farmers and leaders in Africa and in Canada. These are typically systems of inequality, weak governments and \
			isolated rural populations.</p> \
			<p>Run to End Poverty is an opportunity to align my beliefs with my actions, and share with my network the hope \
			I have that change is happening, and the belief that we can play a part in it.</p> \
			<p>Engineers Without Borders is an organization that drives this change, which is why I am happy to say that all \
			dollars raised through my run will be going to support them and their work.</p>",
		'Running for the Team': "I'm running because I'm a runner. I've been logging kilometres for years - to stay fit, to \
			be healthy and to keep moving. These are my goals, and they're important ones too.</p> \
			<p>I could have chosen any race. I could have kept to my well-worn neighbourhood trail. I'm choosing to run with \
			the Run to End Poverty team because I have not yet found a more passionate and committed team of runners. I \
			participate because running requires energy and this team has it in spades. As part of Run to End Poverty I am \
			joining a movement of change-makers across the country who are working together to change the way Canadians think \
			about development in Africa, and what's more, raise money to improve the way we participate in development in Africa.",
		'Outsmarting Poverty with EWB': "<p>Poverty is the product of broken systems that prevent people from realizing their full \
			potential. Beating poverty means making those systems work.</p> \
			<p>Engineers Without Borders Canada (EWB) is doing exactly that. They invest in people-smart systems changers and \
			incubate systemic innovations that they create to accelerate rural African development. It's not about projects. It's \
			not about technology. It's about people working with people to create lasting, scalable change that unlocks human \
			potential.</p> \
			<p>I am running to support Engineers Without Borders Canada and I hope you can help contribute to my campaign!</p> \
			<h2>We can't just fight poverty</h2> \
			<p>The last decade has seen significant progress and success in Africa's development, specifically in areas that \
			involve clear cause-and-effect relationships. Vaccinating children saves lives. Building schools breaks the cycle of \
			poverty and creates prosperity through education. In instances like these, significant external investments can \
			successfully \"fight\" poverty.</p> \
			<p>However, it's not always that simple. Cause and effect aren't always so clearly defined, and applying the same direct \
			approach to a more complex problem is often ineffective or detrimental. Governance, Market development, Agriculture. The \
			same model of external intervention ends up addressing the problems, but not solving them. Wells for those who are \
			thirty or subsidized agriculture goods for farmers both seem like logical interventions. But what happens when the well \
			breaks down, or farmers lack access to market to sell their crops? Or worse, what happens when external help creates \
			dependency and causes African leaders to make decisions based on donor expectations?</p> \
			<p>In the case of complex developmental issues, massive institutional and individual investment can only serve to \
			address symptoms, when the need is to be looking at the system.</p> \
			<h2>We must outsmart poverty</h2> \
			<p>Different approaches are required when the problem involves significant interdependencies. They are rooted in \
			detailed systems analysis, establishing and testing hypotheses, and the identification of influencers and leverage \
			points. The path to real change is rarely clear, and what's needed is an iterative, flexible approach that leaves \
			room for failure, learning and refinement before last impact is achieved.</p> \
			<p>This intelligent approach lies at the heart of EWB Canada's work to outsmart poverty. The staff, members and \
			volunteers ask why there are no wells, not how can be drilled. They ask why farmers fail to prosper, not how we can \
			get them fertilizer.</p> \
			<p>That's EWB Canada's path to systemic change and lasting impact - they identify incredibly talented people in \
			Africa and Canada, and help them realize their full potential as change-makers.</p> \
			<p>Donate to my run and help outsmart poverty!</p>",
	}

	$(function() {
		var $select = $('#edit-canned-message'),
			$title = $('#edit-title'),
			$body = $('#edit-body-und-0-value'),
			$toggle = $('#wysiwyg-toggle-edit-body-und-0-value');

		$select.change(function() {
			if ($select.val() == 'none') {
				return;
			}

			$toggle.click();
			$title.val($select.val());
			$body.val(messages[$select.val()]);
			$toggle.click();
		});
	})
}(jQuery));


