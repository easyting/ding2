<?php
/**
 * @file
 * Template file for taxonomy-like layout.
 */
$title = $item->title;
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$lead = field_get_items('node', $item, 'field_ding_event_lead');
$teaser = field_get_items('node', $item, 'field_ding_event_body');
?>

<div class="image">
  <?php if (!$image): ?>
    <span class="no-image"></span>
  <?php else: ?>
    <a href="<?php print url('node/' . $item->nid); ?>">
      <?php print theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))); ?>
    </a>
  <?php endif; ?>
</div>

<div class="info">
  <h3><?php print l($title, 'node/' . $item->nid); ?></h3>
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
</div>
