<?php

/**
 * @file
 * Template file for taxonomy-like layout.
 */
$title = $item->title;
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$back_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));
?>

<div class="image">
  <?php if (!$image): ?>
    <span class="no-image"></span>
  <?php else: ?>
    <?php print $back_image; ?>
  <?php endif; ?>
</div>

<div class="info">
  <h3><?php print l($title, 'node/' . $item->nid); ?></h3>
  <p>
    <?php print $item->teaser_lead; ?>
  </p>
</div>
