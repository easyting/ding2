<?php
/**
 * @file
 * Ding event node blocks template.
 */
$category = field_view_field('node', $item, 'field_ding_event_category', array('label' => 'hidden', 'type' => 'taxonomy_term_reference_plain'));
$lead     = field_view_field('node', $item, 'field_ding_event_lead', array(
  'label'    => 'hidden',
  'type'     => 'text_trimmed',
  'settings' => array('trim_length' => 120),
));
$library = field_view_field('node', $item, 'og_group_ref', array('label' => 'hidden', 'type' => 'entityreference_label', 'settings' => array('link' => FALSE)));

$event_period = field_get_items('node', $item, 'field_ding_event_date');
$event_date   = _ding_nodelist_format_event_date($item);
$event_hours  = _ding_nodelist_format_event_time($item);

$image_field = 'field_' . $item->type . '_list_image';
$image       = _ding_nodelist_get_dams_image_info($item, $image_field);
$img_url     = FALSE;
if (!empty($image['path'])) {
  $img_url = image_style_url($conf['image_style'], $image['path']);
}
?>

<article
    class="node node-ding-event node-promoted node-teaser nb-item <?php print (!empty($image)) ? 'has-image' : ''; ?>">
  <a href="<?php print '/node/' . $item->nid; ?>">
    <div class="inner">
      <div class="background">
        <div class="button"><?php print t('Read more'); ?></div>
      </div>
      <div class="event-text">
        <div class="info-top">
          <?php print drupal_render($category); ?>
        </div>
        <div class="date"><?php print $event_date; ?></div>
        <div class="title-and-lead" style="">
          <h3
              class="title"><?php print $item->title; ?></h3>
          <?php print drupal_render($lead); ?>
        </div>
        <div class="info-bottom">
          <div class="library">
            <?php print drupal_render($library); ?>
          </div>
          <div class="date-time"><?php print $event_hours; ?></div>
          <div class="price">
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
          </div>
        </div>
      </div>
    </div>
    <?php if (!empty($image)): ?>
      <div class="event-list-image nb-image"
           style="background-image:url(<?php print $img_url; ?>);"></div>
    <?php endif; ?>
  </a>
</article>
