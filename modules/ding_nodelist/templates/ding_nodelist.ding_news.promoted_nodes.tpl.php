<?php

/**
 * @file
 * Ding news promoted nodes template.
 */

$title = $item->title;
$image_field = 'field_' . $item->type . '_list_image';
$image_path = _ding_nodelist_get_image_path($item, $conf, $image_field);
$condition = ($class[0] == 'first' && $class[1] == 'left' || $class[0] == 'last' && $class[1] == 'right');

$classes = array();
$classes[] = "ding_nodelist-pn-item";
$classes[] = (empty($image_path) ? 'no-bgimage' : NULL);
$classes[] = (isset($item->has_video) ? 'has-video' : NULL);
$classes = implode(" ", $classes);
?>
<div
  class="<?php print $classes; ?>"
  <?php if (!empty($image_path)): ?>
    <?php if ($condition): ?>
      style="background: url(<?php print $image_path; ?>);"
    <?php endif; ?>
  <?php endif; ?>
>
  <?php if (isset($item->has_video)): ?>
    <div class="media-container">
      <div class="media-content"
           data-url="<?php print $item->has_video; ?>"></div>
      <div class="close-media"><i class="icon-cross"></i></div>
    </div>
  <?php endif; ?>
  <div class="news-info">
    <h3><?php print l($title, 'node/' . $item->nid); ?></h3>
    <div class="item-body">
      <?php print $item->teaser_lead; ?>
    </div>

    <div class="read-more">
      <?php print l(t('Read more'), 'node/' . $item->nid); ?>
    </div>

    <?php if (isset($item->has_video)): ?>
      <div class='media-play'>
        <div class='play round'><i class='icon-play'></i></div>
      </div>
    <?php endif; ?>

  </div>
</div>
