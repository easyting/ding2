<?php
/**
 * @file
 * Node blocks list widget template.
 */
?>
<?php if ($items): ?>
  <div class="<?php print $conf['classes'] ?>">
    <?php if (!empty($conf['title'])): ?>
      <h2 class="ding_nodelist-title"><?php print $conf['title']; ?></h2>
    <?php endif; ?>
    <div class="ding_nodelist-items">
      <?php
      $items = array_slice($items, 0, 8);
      foreach ($items as $k => $node) {
        print theme($node->item_template, array(
          'item' => $node,
          'conf' => $conf,
        ));
      }
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
