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
$category = field_view_field('node', $item, 'field_ding_event_category', 'default');
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$event_date = _ding_nodelist_get_event_date($item);
$event_time = _ding_nodelist_get_event_time($item);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$back_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));
?>

<?php if (isset($item->has_header)): ?>
  <div class="event-list-leaf">
    <div class="event-list-date-wrapper">
      <span class="event-list-day">
        <?php print t('@day', array('@day' => date('D', $event_date))); ?>
      </span>
      <div class="event-list-inner-wrapper">
        <span class="event-list-date">
          <?php print format_date($event_date, 'day_only'); ?>
        </span>
        <span class="event-list-month">
          <?php print format_date($event_date, 'short_month_only'); ?>
        </span>
      </div>
    </div>
  <span class="event-list-fulldate">
    <?php print format_date($event_date, 'ding_long_date_only'); ?>
  </span>
  </div>
<?php endif; ?>
<div class="item">
  <?php if (!empty($image)): ?>
    <div class="item-list-image">
      <?php print $back_image; ?>
    </div>
  <?php endif ?>
  <div class="item-details">
    <h2 class="item-title"><?php print l($title, 'node/' . $item->nid); ?></h2>
    <span class="item-library"><?php print $library[0]['#markup']; ?></span>
    <div class="item-date"><?php print $event_time; ?></div>
    <div class="item-price">
      <?php
      $fee_field = field_get_items('node', $item, 'field_ding_event_price');
      if (is_array($fee_field)) {
        // @todo: Move logic from templates.
        $fee = current($fee_field);
        print $fee['value'] . ' ' . $currency;
      }
      else {
        print t('Free');
      }
      ?>
    </div>
    <div class="item-body">
      <span><?php print $item->teaser_lead; ?></span>
    </div>
    <div class="event-arrow-link">
      <?php print l('<i class="icon-chevron-right"></i>', 'node/' . $item->nid, array('html' => TRUE)); ?>
    </div>
  </div>
</div>
