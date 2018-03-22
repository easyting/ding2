<?php

/**
 * @file
 * Template file for taxonomy-like layout.
 *
 * Available variables:
 *
 * $title
 *   Node title.
 * $body
 *   Node body teaser.
 * $image
 *   Node list image html tag.
 * $date
 *   Node date, created or published if set.
 * $author
 *   Node author name.
 */

$title = $item->title;
$category = field_view_field('node', $item, 'field_ding_news_category', 'default');
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
if (!empty($item->publish_on)) {
  $date = $item->publish_on;
}
else {
  $date = $item->created;
}
$date = format_date($date, 'ding_long_date_only', 'd/m/Y');
$author = l($item->name, 'user/' . $item->uid);
$author = t('by !author', array('!author' => $author));
$back_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));
?>
<div class="item">
  <?php if (!empty($image)): ?>
    <div class="item-list-image">
      <?php print $back_image; ?>
    </div>
  <?php endif ?>
  <div class="item-details news">
    <h2 class="item-title"><?php print l($title, 'node/' . $item->nid); ?></h2>
    <div class="item-byline">
      <div class="label"><?php print drupal_render($category); ?></div>
      <div class="author"><?php print $author; ?></div>
    </div>
    <div class="item-body">
      <?php print $item->teaser_lead; ?>
    </div>
    <div class="news-link more-link">
      <?php print l(t('Read more'), 'node/' . $item->nid); ?>
    </div>
  </div>
</div>
