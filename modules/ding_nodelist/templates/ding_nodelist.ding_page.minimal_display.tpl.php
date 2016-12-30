<?php
/**
 * @file
 * Minimal display page display template.
 */
$title = $item->title;
$date = date('d/m', $item->created);
?>
<div class="minimal-item <?php print $class; ?>">
  <div class="minimal-title"><?php print l($title, 'node/' . $item->nid); ?></div>
  <div class="minimal-date"><?php print $date; ?></div>
</div>
