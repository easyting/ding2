<?php
/**
 * @file
 * Ding event promoted nodes template.
 */
$title = $item->title;
$image_field = 'field_' . $item->type . '_list_image';
$image_path = _ding_nodelist_get_image_path($item, $conf, $image_field);
$lead = field_get_items('node', $item, 'field_ding_event_lead');
$teaser = field_get_items('node', $item, 'field_ding_event_body');
$event_date = _ding_nodelist_get_event_date($item);
$event_date_formatted = _ding_nodelist_formated_ding_event_date($item);
$library = field_view_field('node', $item, 'og_group_ref', 'default');
$price = field_view_field('node', $item, 'field_ding_event_price', 'default');
$category = field_view_field('node', $item, 'field_ding_event_category', 'teaser');
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
  <div class="event-info">
    <h3><?php print l($title, 'node/' . $item->nid); ?></h3>
    <div class="item-body">
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
    </div>
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
