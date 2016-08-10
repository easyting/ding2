<?php

/**
 * @file
 * Represents field definitions and implementation of field hooks.
 */

/**
 * Implements hook_field_info().
 */
function ding_mkws_field_info() {
  return array(
    'ding_mkws_node' => array(
      'label' => t('Ding mkws node'),
      'description' => t('Field which represents a mkws widget for node.'),
      'default_widget' => 'ding_mkws_node_widget_default',
      'default_formatter' => 'ding_mkws_node_formatter_default',
    ),
  );
}
