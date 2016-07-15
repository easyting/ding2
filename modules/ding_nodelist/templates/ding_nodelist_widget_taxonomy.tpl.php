<?php
/**
 * @file
 * Slider list widget template.
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
