<?php

/**
 * @file
 * Ding news single item template.
 */

$image_field = 'field_' . $item->type . '_list_image';
$image = _ding_nodelist_get_dams_image_info($item, $image_field);
$category = field_view_field('node', $item, 'field_ding_news_category', 'teaser');
$back_image = l($image ? theme('image_style', array_merge($image, array('style_name' => $conf['image_style']))) : '', 'node/' . $item->nid, array('html' => TRUE));

$classes = array();
$classes[] = "item";
$classes[] = (isset($item->has_video) ? 'has-video' : NULL);
$classes = implode(" ", $classes);
?>
<div class="<?php print $classes; ?>">
  <?php if (isset($item->has_video)): ?>
    <div class="media-container">
      <div class="media-content"
           data-url="<?php print $item->has_video; ?>"></div>
      <div class="close-media"><i class="icon-cross"></i></div>
    </div>
  <?php endif; ?>

  <div class="event-info">
    <div class="article_image">
      <?php print $back_image; ?>
    </div>
    <div class="article-info">
      <div class="label"><?php print drupal_render($category); ?></div>
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
    <?php if (isset($item->has_video)): ?>
      <div class='media-play'>
        <div class='play round'><i class='icon-play'></i></div>
      </div>
    <?php endif; ?>
  </div>
</div>
