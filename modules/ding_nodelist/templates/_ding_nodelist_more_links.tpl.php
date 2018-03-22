<?php

/**
 * @file
 * Template for "More links" block.
 */
?>
<div class="more-links">
  <ul>
    <?php foreach ($links as $key => $link) : ?>
      <li>
        <div class="more-link"> <?php print l(t($link['text']), $link['links']); ?></div>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
