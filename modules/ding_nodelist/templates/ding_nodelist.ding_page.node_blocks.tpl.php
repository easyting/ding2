<?php

/**
 * @file
 * Ding page node blocks template.
 */
$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$img_url = FALSE;
if (!empty($image['path'])) {
  $img_url = image_style_url($conf['image_style'], $image['path']);
}
$lead = field_view_field('node', $item, 'field_ding_page_lead', array('label' => 'hidden', 'type' => 'text_trimmed', 'settings' => array('trim_length' => 120)));
$library = field_view_field('node', $item, 'ding_page_group_ref', array('label' => 'hidden', 'type' => 'entityreference_label', 'settings' => array('link' => TRUE)));
?>

<article class="node node-ding-event node-promoted node-teaser nb-item <?php print (!empty($image)) ? 'has-image' : ''; ?>">
  <div class="inner">
    <div class="background">
      <div class="button"><?php print l(t('Read more'), 'node/' . $item->nid); ?></div>
    </div>
    <div class="event-text">
      <div class="title-and-lead">
        <h3 class="title"><?php print l($item->title, 'node/' . $item->nid); ?></h3>
        <?php print drupal_render($lead); ?>
      </div>
      <div class="info-bottom">
        <div class="library">
          <?php print drupal_render($library); ?>
        </div>
      </div>
    </div>
  </div>
  <?php if(!empty($image)): ?>
    <div class="event-list-image nb-image" style="background-image:url(<?php print $img_url; ?>);"></div>
  <?php endif; ?>
</article>
