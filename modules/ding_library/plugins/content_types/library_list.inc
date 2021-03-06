<?php
/**
 * @file
 * Creates a library select dropdown pane.
 */

$plugin = array(
  'title' => t('Ding library selection dropdown'),
  'description' => t('Display a selection dropdown with available libraries.'),
  'single' => TRUE,
  'edit form' => 'ding_library_library_list_content_type_edit_form',
  'render callback' => 'ding_library_library_list_content_type_render',
  'category' => t('Ding!'),
  'required context' => array(
    new ctools_context_optional(t('Taxonomy term id'), array('term', 'taxonomy_term')),
    new ctools_context_optional(t('Library'), 'node'),
  ),
  'defaults' => array(
    'hide_default' => FALSE,
    'slug' => '',
  ),
);

/**
 * Implements hook_ID_content_type_render().
 */
function ding_library_library_list_content_type_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $library = NULL;
  $selected_term = NULL;
  $selected_url = NULL;
  $suffix = '';

  // Taxonomy term as first context.
  if (isset($context[0]->data)) {
    $selected_term = $context[0]->data;
    $suffix = '/' . $selected_term->tid;
    $alias = drupal_lookup_path('alias', 'taxonomy/term/' . $selected_term->tid);
  }

  // Library node as context.
  if (isset($context[1]->data)) {
    $library = $context[1]->data;
    $uri = entity_uri('node', $library);
    $selected_url = drupal_lookup_path('alias', $uri['path']) . '/' . $conf['slug'] . $suffix;
  }

  // Get all active library title and nid's.
  $nodes = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'ding_library')
    ->condition('status', '1')
    ->execute()
    ->fetchAll();

  // Generate link for each library.
  if (!empty($nodes)) {
    // Filter out the nodes that are "owned" by the active domain.
    if (module_exists('domain')) {
      $domain = domain_get_domain();

      foreach ($nodes as $k => $node) {
        $node_domain = domain_get_node_match($node->nid);

        if ($node_domain['domain_id'] != $domain['domain_id']) {
          unset($nodes[$k]);
        }
      }
    }

    uasort($nodes, 'ding_library_library_list_sort_title');

    $items = array();
    if (isset($conf['hide_default']) && !$conf['hide_default']) {
      $items = array($conf['slug'] . $suffix => t('All libraries'));
      if (isset($alias)) {
        $items = array($alias => t('All libraries'));
      }
    }

    foreach ($nodes as $node) {
      $node_path = 'node/' . $node->nid;
      $node_alias = drupal_lookup_path('alias', $node_path);
      $path_args =  '/' . $conf['slug'] . $suffix;
      // If we have a alias then use it, else use original path.
      $uri = !empty($node_alias) ? $node_alias . $path_args : $node_path . $path_args;
      $items[$uri] = $node->title;
    }

    // Generate the select box form.
    $links = array();

    foreach ($items as $href => $title) {
      $links[] = array(
        'title' => $title,
        'href' => $href,
        'attributes' => array('class' => array('list-item')),
      );
    }

    $block->content = array(
      '#theme' => 'links',
      '#links' => $links,
      '#attributes' => array(
        'class' => array('list-items'),
      ),
      '#heading' => array(
        'text' => t('Select library'),
        'level' => 'h2',
        'class' => array('list-title', 'sub-menu-title'),
      ),
      '#prefix' => '<div class="select-list">',
      '#suffix' => '</div>',
    );
  }

  return $block;
}

/**
 * Helper function to sort libraries based on name.
 */
function ding_library_library_list_sort_title($a, $b) {
  if (!isset($b->title)) {
    return -1;
  }

  if (!isset($a->title)) {
    return 1;
  }

  return strcasecmp($a->title, $b->title);
}

/**
 * Edit form callback for the content type.
 */
function ding_library_library_list_content_type_edit_form($form, &$form_state) {
  // Get node types.
  $options = array();
  $types = node_type_get_types();
  foreach ($types as $type) {
    $options[$type->type] = $type->name;
  }
  $form['hide_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide default'),
    '#description' => t('Should the drop-down hide the "All libraries" option.'),
    '#default_value' => $form_state['conf']['hide_default'],
  );

  $form['slug'] = array(
    '#type' => 'textfield',
    '#title' => t('Slug'),
    '#description' => t('The slug could be "arrangementer" or "nyheder" and will be inserted based on the context.'),
    '#default_value' => $form_state['conf']['slug'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Submit handler for the admin edit form.
 */
function ding_library_library_list_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
