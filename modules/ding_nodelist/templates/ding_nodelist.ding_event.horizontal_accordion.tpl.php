<?php

/**
 * @file
 * Ding event horizontal accordion template.
 */

$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$event_date = _ding_nodelist_get_event_date($item);
$event_date_formatted = _ding_nodelist_format_event_time($item);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$category = field_view_field('node', $item, 'field_ding_event_category', 'default');
$back_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));
?>
<li class="event item">
  <div class="item_content">
    <div class="expand"><?php print l($item->title, 'node/' . $item->nid);?></div>
    <div class="event-time">
      <div class="event-day"><?php print format_date($event_date, 'custom', 'D'); ?></div>
      <div class="event-date"><?php print format_date($event_date, 'day_only'); ?></div>
      <div class="event-month"><?php print format_date($event_date, 'short_month_only'); ?></div>
    </div>
    <div class="image">
      <?php print $back_image; ?>
    </div>
    <div class="data">
      <div class="caption">
        <h3 class="node-title">
          <?php print l($item->title, 'node/' . $item->nid);?>
        </h3>
      </div>
      <div class="library">
        <div class="event-timestamp">
          <span><?php print t('Time:');?></span>
          <span><?php print $event_date_formatted;?></span>
        </div>
       
        <div class="event-details">
          <span class="event-library">
            <?php print $library[0]['#markup']; ?>
          </span>
          <span class="event-fee">
            <?php
              $fee_field = field_get_items('node', $item, 'field_ding_event_price');
              if (is_array($fee_field)) {
                $fee = current($fee_field);
                print '&mdash; ' . $fee['value'] . ' ' . $currency;
              }
              else {
                print '&mdash; ' . t('Free');
              }
            ?>
          </span>
        </div>
      </div>
      <div class="teaser">
          <p>
            <?php print $item->teaser_lead; ?>
          </p>
       </div>
    </div>
  </div>
</li>
