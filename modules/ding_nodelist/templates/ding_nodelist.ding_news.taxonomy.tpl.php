<?php
/**
 * @file
 * Template file for taxonomy-like layout.
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
$lead = field_get_items('node', $item, 'field_ding_news_lead');
$teaser = field_get_items('node', $item, 'field_ding_news_body');

/**
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
?>
<div class="item">
  <?php if (!empty($image)): ?>
    <div class="item-list-image">
      <a href="<?php print url('node/' . $item->nid); ?>">
        <?php print $image ? theme('image_style', array_merge($image, array('style_name' => 'ding_list_large'))) : ''; ?>
      </a>
    </div>
  <?php endif ?>
  <div class="item-details">
    <h2 class="item-title"><?php print l($title, 'node/' . $item->nid); ?></h2>
    <div class="item-byline">
      <div class="label"><?php print drupal_render($category); ?></div>
      <div class="date"><?php print render($date); ?></div>
      <div class="author"><?php print $author; ?></div>
    </div>
    <div class="item-body">
      <?php
      // @todo: Move logic from templates.
      if (isset($lead[0]['safe_value'])) {
        print strip_tags($lead[0]['safe_value']);
      }
      elseif (isset($teaser[0]['safe_value'])) {
        print strip_tags($teaser[0]['safe_value']);
      }
      else {
        print '';
      }
      ?>
    </div>
    <div class="news-link">
      <?php print l(t('Read more'), 'node/' . $item->nid); ?>
    </div>
  </div>
</div>
