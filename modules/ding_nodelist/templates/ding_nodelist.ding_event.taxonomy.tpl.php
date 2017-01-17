<?php
/**
 * @file
 * Template file for taxonomy-like layout.
 */

$title = $item->title;
$category = field_view_field('node', $item, 'field_ding_event_category', 'default');
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$event_date = _ding_nodelist_get_event_date($item);
$event_time = _ding_nodelist_get_event_time($item);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$library = drupal_render($library);
$lead = field_get_items('node', $item, 'field_ding_event_lead');
$teaser = field_get_items('node', $item, 'field_ding_event_body');

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
      <a href="<?php print url('node/' . $item->nid); ?>">
        <?php print $image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : ''; ?>
      </a>
    </div>
  <?php endif ?>
  <div class="item-details">
    <h2 class="item-title"><?php print l($title, 'node/' . $item->nid); ?></h2>
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
    <span class="item-library"><?php print $library; ?></span>
    <div class="item-date"><?php print $event_time; ?></div>
    <div class="item-price">
      <?php
      $fee_field = field_get_items('node', $item, 'field_ding_event_price');
      if (is_array($fee_field)) {
        // @todo: Move logic from templates.
        $fee = current($fee_field);
        print $fee['value'] . ' ' . t('kr.');
      }
      else {
        print t('Free');
      }
      ?>
    </div>
    <div class="event-arrow-link">
      <a href="<?php print url('node/' . $item->nid); ?>">
        <i class="icon-chevron-right"></i>
      </a>
    </div>
  </div>
</div>
