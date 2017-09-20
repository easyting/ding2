<?php

/**
 * @file
 * Template for "More links" block.
 */
?>
<div class="more-links">
  <ul>
    <?php foreach ($links as $key => $bottom) : ?>
      <li>
        <?php print l($bottom['text'], $bottom['links']); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
