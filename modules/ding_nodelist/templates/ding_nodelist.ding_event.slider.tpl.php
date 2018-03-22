<?php

/**
 * @file
 * Ding event slider template.
 */

$category = field_view_field('node', $item, 'field_ding_event_category', array('label' => 'hidden', 'type' => 'taxonomy_term_reference_link'));
$event_date = _ding_nodelist_formated_ding_event_date($item);
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
$library = field_view_field('node', $item, 'og_group_ref', 'default');
?>
<li class="item">
  
  <h3 class="node-title">
      <?php print l($item->title, 'node/' . $item->nid); ?>
  </h3>
  <div class="category">
    <span class="label label-info"><?php print drupal_render($category);?></span>
  </div>
  <div class="node">
    <div class="item-date">
      <?php print $event_date; ?>
    </div>
    <div class="event-details">
      <span class="library"><?php print $library[0]['#markup']; ?></span>
      <span class="item-price">
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
    <div class="item-body">
      <?php print $item->teaser_lead; ?>
    </div>
  </div>
  <div class="more"><?php print l(t('More'), 'node/' . $item->nid);?></div>
</li>
