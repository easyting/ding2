<?php
/**
 * @file
 * Ding news node blocks template.
 */
$lead = field_get_items('node', $item, 'field_' . $item->type . '_lead');
$teaser = field_get_items('node', $item, 'field_' . $item->type . '_body');
?>
<div class="nb-item <?php print $item->type; ?>">
  <div class="nb-inner">
    <h3><?php print l($item->title, 'node/' . $item->nid); ?></h3>
    <div class="nb-event-summary">
      <?php
      if (isset($lead[0]['safe_value'])) {
        print strip_tags($lead[0]['safe_value']);
      }
      elseif (isset($teaser[0]['safe_value'])) {
        print strip_tags($teaser[0]['safe_value']);
      }
      else {
        print '';
      }
      ?>
    </div>
  </div>
</div>
