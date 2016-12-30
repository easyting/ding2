<?php
/**
 * @file
 * Ding event single item template.
 */

if ($variables['conf']['sorting'] == 'event_date') {
  // Get the object from the array in the case we are sorting by date.
  $item = array_shift(array_values($item));
}
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$category = field_view_field('node', $item, 'field_ding_event_category', 'teaser');
$event_date = _ding_nodelist_get_event_date($item);
$event_date_formatted = _ding_nodelist_formated_ding_event_date($item);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
$lead = field_get_items('node', $item, 'field_ding_event_lead');
$teaser = field_get_items('node', $item, 'field_ding_event_body');

$classes = array();
$classes[] = "item";
$classes[] = (isset($item->has_video) ? 'has-video' : NULL);
$classes = implode(" ", $classes);
?>
<div class="<?php print $classes; ?>">
  <?php if (isset($item->has_video)): ?>
    <div class="media-container">
      <div class="media-content"
           data-url="<?php print $item->has_video; ?>"></div>
      <div class="close-media"><i class="icon-cross"></i></div>
    </div>
  <?php endif; ?>
  <div class="event-info">
    <div class="event-image">
      <a
        href="<?php print url('node/' . $item->nid); ?>"><?php print $image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : ''; ?></a>
    </div>
    <div class="event-time">
      <div class="event-day"><?php print t(date('D', $event_date)); ?></div>
      <div
        class="event-date"><?php print format_date($event_date, 'day_only'); ?></div>
      <div
        class="event-month"><?php print format_date($event_date, 'short_month_only'); ?></div>
    </div>
    <div class="article-info">
      <div class="label"><?php print drupal_render($category); ?></div>
      <div class="node">
        <h3 class="node-title"><a
            href="<?php print url('node/' . $item->nid); ?>"><?php print $item->title; ?></a>
        </h3>
        <div class="item-date"><?php print $event_date_formatted; ?></div>
        <div>
          <span class="library"><?php print drupal_render($library); ?></span>
        <span class="item-price">
          <?php
          $fee_field = field_get_items('node', $item, 'field_ding_event_price');
          if (is_array($fee_field)) {
            $fee = current($fee_field);
            print '&mdash; ' . $fee['value'] . ' ' . t('kr.');
          }
          else {
            print '&mdash; ' . t('Free');
          }
          ?>
        </span>
        </div>
        <p>
          <?php
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
        </p>
        <div class="more">
          <?php print l(t('More'), 'node/' . $item->nid); ?>
        </div>
      </div>
    </div>
    <?php if (isset($item->has_video)): ?>
      <div class='media-play'>
        <div class='play round'><i class='icon-play'></i></div>
      </div>
    <?php endif; ?>
  </div>
</div>
