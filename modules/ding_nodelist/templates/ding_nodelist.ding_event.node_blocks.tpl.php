<?php

/**
 * @file
 * Ding event node blocks template.
 */
$category = field_view_field('node', $item, 'field_ding_event_category', 'teaser');
$event_period = field_get_items('node', $item, 'field_ding_event_date');
$event_date = _ding_nodelist_get_event_date($item);
$event_hours = _ding_nodelist_get_event_hours($event_period);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
?>
<div class="nb-item <?php print $item->type; ?>">
  <div class="nb-inner">
    <div class="nb-event-date">
      <?php print t('@event_date', array('@event_date' => date('D', $event_date))); ?>
    </div>
    <h3><?php print l($item->title, 'node/' . $item->nid); ?></h3>
    <div class="nb-event-summary">
      <?php print $item->teaser_lead; ?>
    </div>
    <div class="nb-library"><?php print $library[0]['#markup']; ?></div>
    <div class="nb-event-info">
      <?php print $event_hours; ?>
      <span class="nb-event-fee">
      <?php
      $fee_field = field_get_items('node', $item, 'field_ding_event_price');
      if (is_array($fee_field)) {
        $fee = current($fee_field);
        print $fee['value'] . ' ' . $currency;
      }
      else {
        print t('Free');
      }
      ?>
    </span>
    </div>

  </div>
</div>
