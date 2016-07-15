<?php
/**
 * @file
 * Single list widget template.
 * Variables are:
 * $items - node items (objects)
 * $conf - list configuration with:
 *  - classes - widget-specific CSS classes
 *  - title - list title
 * $links - list of links (array)
 */
?>
<?php if ($items): ?>
  <div class="<?php print $conf['classes'] ?>">
    <?php if (!empty($conf['title'])): ?>
      <h2 class="ding_nodelist-title"><?php print $conf['title']; ?></h2>
    <?php endif; ?>
    <div class="ding_nodelist-items">
      <?php
      $node = reset($items);
      print theme($node->item_template, array(
        'item' => $node,
        'conf' => $conf,
      ));
      ?>
    </div>
    <?php if (!empty($links)): ?>
      <div class="more-links">
        <ul>
          <?php foreach ($links as $key => $bottom) : ?>
            <li>
              <?php print l(t($bottom['text']), $bottom['links']); ?>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
