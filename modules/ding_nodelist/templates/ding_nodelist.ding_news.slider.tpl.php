<?php

/**
 * @file
 * Ding news slider template.
 */

$category = field_view_field('node', $item, 'field_ding_news_category', 'teaser');
?>
<li class="item">
  <div class="category">
    <?php print drupal_render($category);?>
  </div>
  <h3 class="node-title">
      <?php print l($item->title, 'node/' . $item->nid); ?>
  </h3>
  <div class="node">
    <?php print $item->teaser_lead; ?>
  </div>
  <div class="more"><?php print l(t('More'), 'node/' . $item->nid);?></div>
</li>
