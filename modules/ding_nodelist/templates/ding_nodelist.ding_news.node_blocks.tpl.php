<?php

/**
 * @file
 * Ding news node blocks template.
 */
?>
<div class="nb-item <?php print $item->type; ?>">
  <div class="nb-inner">
    <h3><?php print l($item->title, 'node/' . $item->nid); ?></h3>
    <div class="nb-event-summary">
      <?php print $item->teaser_lead; ?>
    </div>
  </div>
</div>
