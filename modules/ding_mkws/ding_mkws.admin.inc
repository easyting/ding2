<?php
/**
 * @file
 * Represents configuration and settings form.
 */

/**
 * Form handler of configuration page.
 */
function ding_mkws_service_settings_form($form, $form_state) {
  $settings = variable_get('ding_mkws_settings', array());

  $form['pz2'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Pazpar2 settings'),
    '#tree' => TRUE,
  );

  $form['pz2']['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Url of service'),
    '#description' => t('Full url of remote service'),
    '#required' => TRUE,
    '#default_value' => isset($settings['url']) ? $settings['url'] : NULL,
  );

  $form['pz2']['user'] = array(
    '#type' => 'textfield',
    '#title' => t('Service Proxy username'),
    '#description' => t('Service Proxy username'),
    '#required' => TRUE,
    '#default_value' => isset($settings['user']) ? $settings['user'] : NULL,
  );

  $form['pz2']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Service Proxy password'),
    '#description' => t('Service Proxy password'),
    '#required' => TRUE,
    '#default_value' => isset($settings['password']) ? $settings['password'] : NULL,
  );

  $form['pz2']['proxy'] = array(
    '#type' => 'textfield',
    '#title' => t('Pazpar2/Service Proxy URL or path'),
    '#description' => t('URL that takes Pazpar2 commands via HTTP, can be a relative path eg. for httpd proxying'),
    '#required' => TRUE,
    '#default_value' => isset($settings['proxy']) ? $settings['proxy'] : NULL,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#validate' => array('ding_mkws_service_settings_form_validate'),
    '#submit' => array('ding_mkws_service_settings_form_submit'),
  );

  return $form;
}

/**
 * Validate handler for pz2 settings form.
 */
function ding_mkws_service_settings_form_validate($form, &$form_state) {
  $pz2 = $form_state['values']['pz2'];

  if (!valid_url($pz2['url'], TRUE)) {
    form_set_error('pz2][url', t('Enter valid url.'));
  }

  if (!valid_url($pz2['proxy'], FALSE)) {
    form_set_error('pz2][proxy', t('Enter valid url for proxy.'));
  }
}

/**
 * Submit handler for saving pz2 settings.
 */
function ding_mkws_service_settings_form_submit($form, &$form_state) {
  $pz2 = $form_state['values']['pz2'];
  variable_set('ding_mkws_settings', $pz2);
}

/**
 * Form handler of widget configuration.
 */
function ding_mkws_widget_settings_form($form, $form_state) {
  $form['#tree'] = TRUE;
  $resources = _ding_mkws_process_resources();
  $form['resources'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Available resources'),
  );
  $form['resources']['values'] = array(
    '#type' => 'checkboxes',
    '#options' => $resources,
  );

  $form['opac'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('OPAC'),
  );

  $items = array(
    'search' => t('Search result'),
    'collection' => t('Collection view'),
    'item' => t('Item page'),
  );

  foreach ($items as $key => $title) {
    $form['opac'][$key] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#title' => $title,
    );

    $name = "ding_mkws_opac_{$key}_show";
    $form['opac'][$key]['show'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show the widget on @item', array('@item' => drupal_strtolower($title))),
      '#default_value' => variable_get($name, NULL),
    );

    $name = "ding_mkws_opac_{$key}_amount";
    $form['opac'][$key]['amount'] = array(
      '#type' => 'textfield',
      '#title' => t('Amount items in the widget'),
      '#default_value' => variable_get($name, NULL),
    );

    $name = "ding_mkws_opac_{$key}_resources";
    $form['opac'][$key]['resources'] = array(
      '#type' => 'select',
      '#options' => $resources,
      '#title' => t("LBR's to search for this widget"),
      '#default_value' => variable_get($name, NULL),
    );
  }

  return $form;
}
