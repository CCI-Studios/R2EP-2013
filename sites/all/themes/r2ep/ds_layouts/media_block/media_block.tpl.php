<div class="mediaBlock <?php print $classes;?> clearfix">

	<?php if (isset($title_suffix['contextual_links'])): ?>
		<?php print render($title_suffix['contextual_links']); ?>
	<?php endif; ?>

	<?php if ($header): ?>
		<div class="mediaBlock-header <?php print $top_classes ?> clearfix">
			<?php print $header; ?>
		</div>
	<?php endif; ?>

	<?php if ($media || $body): ?>
		<div class="mediaBlock-content">
			<?php if ($media): ?>
				<div class="mediaBlock-media <?php print $media_classes ?>">
					<?php print $media; ?>
				</div>
			<?php endif; ?>

			<?php if ($body): ?>
				<div class="mediaBlock-body <?php print $body_classes ?>">
					<?php print $body; ?>
				</div>
			<?php endif; ?>
		</div>
	<?php endif; ?>

	<?php if ($footer): ?>
		<div class="mediaBlock-Footer<?php print $footer_classes ?>">
			<?php print $footer; ?>
		</div>
	<?php endif; ?>

</div>