<?php

/**
 * @file
 * Simple list widget template.
 *
 * Variables are:
 * $items - node items (objects)
 * $conf - list configuration with:
 *  - classes - widget-specific CSS classes
 *  - title - list title
 * $links - list of links (array)
 */
?>
<?php if ($items): ?>
  <?php if (!empty($conf['title'])): ?>
    <h2 class="pane-title"><?php print $conf['title']; ?></h2>
  <?php endif; ?>
  <div class="<?php print $conf['classes'] ?>">
    <div class="ding_nodelist-items">
      <?php
      foreach ($items as $node) {
        print theme($node->item_template, array('item' => $node));
      }
      ?>
    </div>
    <?php if (!empty($links)): ?>
      <?php print theme('_more_links', array('links' => $links)); ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
