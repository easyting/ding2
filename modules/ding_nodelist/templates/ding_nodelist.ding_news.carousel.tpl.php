<?php

/**
 * @file
 * Ding news image and text template.
 */

$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$category = field_view_field('node', $item, 'field_ding_news_category', array('label' => 'hidden', 'type' => 'taxonomy_term_reference_link'));
$slide_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));
?>
<div class="item">
  <div class="article_image">
    <?php print $slide_image; ?>
  </div>
  <div class="article-info">
    <div class="label-wrapper"><?php print drupal_render($category); ?></div>
    <div class="node">
      <h3 class="node-title">
        <?php print l($item->title, 'node/' . $item->nid); ?>
      </h3>
      <p>
        <?php print $item->teaser_lead; ?>
      </p>
      <div class="more">
        <?php print l(t('More'), 'node/' . $item->nid); ?>
      </div>
    </div>
  </div>
</div>
