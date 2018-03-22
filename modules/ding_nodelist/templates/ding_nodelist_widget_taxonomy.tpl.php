<?php

/**
 * @file
 * Slider list widget template.
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
      $groups = array();
      foreach ($items as $node) {
        $ed = date('d-m-Y', _ding_nodelist_get_event_date($node));
        if (!isset($groups[$ed])) {
          $groups[$ed] = array($node);
        }
        else {
          $groups[$ed][] = $node;
        }
      }

      foreach ($groups as $group) {
        $group[0]->has_header = TRUE;
        foreach ($group as $k => $v) {
          print theme($group[$k]->item_template, array(
            'item' => $group[$k],
            'conf' => $conf,
          ));
        }
      }
      ?>
    </div>
    <?php if (!empty($links)): ?>
      <?php print theme('_more_links', array('links' => $links)); ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
