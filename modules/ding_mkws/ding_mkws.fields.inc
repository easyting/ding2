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

/**
 * Implements hook_field_widget_info().
 */
function ding_mkws_field_widget_info() {
  return array(
    'ding_mkws_node_widget_default' => array(
      'label' => t('Default'),
      'field types' => array('ding_mkws_node'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}


/**
 * Implements hook_field_is_empty().
 */
function ding_mkws_field_is_empty($item, $field) {
  switch ($field['type']) {
    case 'ding_mkws_node':
      return empty($item['wrapper']['term']) || empty($item['wrapper']['resources']);

    default:
      return FALSE;
  }
}

/**
 * Implements hook_field_widget_form().
 */
function ding_mkws_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  switch ($instance['widget']['type']) {
    case 'ding_mkws_node_widget_default':
      $element['wrapper'] = array(
        '#type' => 'fieldset',
        '#title' => t('LBR widget'),
        '#collapsible' => FALSE,
      );

      $item = !empty($items) ? reset($items) : array();
      $element['wrapper']['additional'] = array(
        '#markup' => '<p>' . t('This fieldgroup generates a widget on the node itself. Resources are searched based on the term with amount defined.') . '</p>',
      );

      $element['wrapper']['term'] = array(
        '#type' => 'textfield',
        '#title' => t('Term:'),
        '#default_value' => !empty($item['term']) ? $item['term'] : NULL,
        '#size' => 40,
        '#attributes' => array('placeholder' => t('Type in your term(s) here...')),
      );

      $options = _ding_mkws_process_resources();
      $element['wrapper']['resources'] = array(
        '#type' => 'select',
        '#title' => t('Resources:'),
        '#default_value' => !empty($item['resources']) ? $item['resources'] : NULL,
        '#options' => $options,
        '#empty_option' => t('Choose LBRs'),
      );

      $element['wrapper']['amount'] = array(
        '#type' => 'textfield',
        '#title' => t('Amount:'),
        '#default_value' => !empty($item['amount']) ? $item['amount'] : 10,
        '#element_validate' => array('element_validate_integer_positive'),
        '#size' => 6,
        '#maxlength' => 4,
      );

      $element['#attached'] = array(
        'css' => array(
          drupal_get_path('module', 'ding_mkws') . '/css/ding_mkws.fields.css',
        ),
      );
      break;
  }

  return $element;
}

/**
 * Implements hook_field_presave().
 */
function ding_mkws_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  switch ($instance['widget']['type']) {
    case 'ding_mkws_node_widget_default':
      foreach ($items as $delta => &$item) {
        $item = $item['wrapper'];
      }
      break;
  }
}

/**
 * Implements hook_field_formatter_info().
 */
function ding_mkws_field_formatter_info() {
  return array(
    'ding_mkws_node_formatter_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'ding_mkws_node',
      ),
      'settings' => array(),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function ding_mkws_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  switch ($display['type']) {
    case 'ding_mkws_node_formatter_default':
      list($term, $resources, $amount) = array_values(reset($items));
      $element[0] = array(
        '#markup' => "<div data-term='{$term}' data-resources='{$resources}' data-amount='{$amount}' class='ding-mkws-node-widget'></div>",
        '#attached' => array(
          'css' => array(
            drupal_get_path('module', 'ding_mkws') . '/css/ding_mkws.css',
          ),
          'js' => array(
            drupal_get_path('module', 'ding_mkws') . '/js/ding_mkws.js',
          ),
        ),
      );
      break;
  }
  return $element;
}
