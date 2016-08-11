<?php
/**
 * @file
 * Define items list pane.
 */

/**
 * General ctools plugin settings.
 */
$plugin = array(
  'title' => t('MKWS item list.'),
  'category' => t('Ding!'),
  'description' => t('Add MKWS items as a list.'),
  'single' => TRUE,
  'render callback' => 'ding_mkws_item_list_render',
);

/**
 * Plugin render.
 */
function ding_mkws_item_list_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content['#markup'] = "<div class='ding-mkws-panel-widget'></div>";
  $pane->content['#attached'] = array(
    'css' => array(
      drupal_get_path('module', 'ding_mkws') . '/css/ding_mkws.css',
    ),
    'js' => array(
      drupal_get_path('module', 'ding_mkws') . '/js/ding_mkws.js',
    ),
  );

  return $pane;
}
