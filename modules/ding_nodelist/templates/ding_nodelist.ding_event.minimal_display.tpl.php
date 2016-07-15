<?php
/**
 * @file
 * Minimal display event display template.
 */
$title = $item->title;
$event_date = date('d/m', _ding_nodelist_get_event_date($item));
?>
<div class="minimal-item <?php print $class; ?>">
  <div class="minimal-title"><?php print l($title, 'node/' . $item->nid); ?></div>
  <div class="minimal-date"><?php print $event_date; ?></div>
</div>
