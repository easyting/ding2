<?php

/**
 * @file
 * Ding news node blocks template.
 */
$image_field = 'field_' . $item->type . '_list_image';
$image       = _ding_nodelist_get_dams_image_info($item, $image_field);
$img_url     = FALSE;
if (!empty($image['path'])) {
  $img_url = image_style_url($conf['image_style'], $image['path']);
}

$category = field_view_field('node', $item, 'field_ding_news_category', array(
  'label' => 'hidden',
  'type'  => 'taxonomy_term_reference_plain',
));

$news_date = date('d.m.y', $item->created);
if ($item->created < $item->changed) {
  $news_date = date('d.m.y', $item->changed);
}
?>

<article
    class="node node-ding-news node-promoted node-teaser nb-item <?php print (!empty($image)) ? 'has-image' : ''; ?>">
  <a href="<?php print '/node/' . $item->nid; ?>">
    <div class="inner">
      <div class="background">
        <div class="button"><?php print t('Read more'); ?></div>
      </div>
      <div class="news-text">
        <div class="info-top">
          <?php print drupal_render($category); ?>
        </div>
        <div class="title-and-lead">
          <h3 class="title"><?php print $item->title; ?></h3>
          <div
             class="field field-name-field-ding-news-lead field-type-text-long field-label-hidden">
            <div class="field-items">
              <div class="field-item even">
                <?php print $item->teaser_lead; ?>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php if (!empty($image)): ?>
      <div class="ding-news-list-image nb-image"
           style="background-image:url(<?php print $img_url; ?>);"></div>
    <?php endif; ?>
  </a>
</article>
