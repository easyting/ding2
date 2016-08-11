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
  $global_options = variable_get('ding_mkws_global', array());
  $global_settings = (!empty($global_options['opac'])) ? $global_options['opac'][$subtype] : array();

  $params = array(
    'type' => $subtype,
    'term' => reset($panel_args),
    'amount' => (!empty($global_settings)) ? $global_settings['amount'] : ' 0',
    'resources' => (!empty($global_settings)) ? $global_settings['resources'] : array(),
  );
  $hash = md5(implode('', $params));

  $pane->content['#markup'] = "<div  data-hash='{$hash}' class='ding-mkws-panel-widget'></div>";
  $pane->content['#attached'] = array(
    'css' => array(
      drupal_get_path('module', 'ding_mkws') . '/css/ding_mkws.css',
    ),
    'js' => array(
      drupal_get_path('module', 'ding_mkws') . '/js/ding_mkws.js',
      array(
        'type' => 'setting',
        'data' => array(
          $hash => $params,
        ),
      ),
    ),
  );

  return $pane;
}
