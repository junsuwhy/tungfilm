<?php

/**
 * @file
 * Etherpad editor specifications for the WYSIWYG module.
 */

/**
 * Implements hook_INCLUDE_editor().
 */
function etherpad_etherpad_lite_editor() {
  $editor['etherpad_lite'] = array(
    'title' => 'Etherpad lite editor',
    'vendor url' => 'https://github.com/ether/etherpad-lite-jquery-plugin',
    'download url' => 'https://github.com/ether/etherpad-lite-jquery-plugin/releases',
    'library path' => wysiwyg_get_path('etherpad-lite-jquery-plugin'),
    'libraries' => array(
      'src' => array(
        'title' => 'Source',
        'files' => array(
          'js/etherpad.js',
        ),
      ),
    ),
    'version callback' => 'etherpad_etherpad_lite_version',
    'themes callback' => 'etherpad_etherpad_lite_themes',
    'load callback' => 'etherpad_etherpad_lite_load',
    'settings callback' => 'etherpad_etherpad_lite_settings',
    'plugin callback' => 'etherpad_etherpad_lite_plugins',
    'versions' => array(
      '0.4' => array(
        'js files' => array('etherpad-0.4.js'),
      ),
    ),
  );
  return $editor;
}

/**
 * Detect editor version.
 *
 * @param $editor
 *   An array containing editor properties as returned from hook_editor().
 *
 * @return
 *   The installed editor version.
 */
function etherpad_etherpad_lite_version($editor) {
  $library = $editor['library path'] . '/js/etherpad.js';
  if (!file_exists($library)) {
    return;
  }
  /**
   * TODO: No real way to do this so just returning something
   */
  return "0.4";
}

/**
 * Determine available editor themes or check/reset a given one.
 *
 * @param $editor
 *   A processed hook_editor() array of editor properties.
 * @param $profile
 *   A wysiwyg editor profile.
 *
 * @return
 *   An array of theme names. The first returned name should be the default
 *   theme name.
 */
function etherpad_etherpad_lite_themes($editor, $profile) {
  $js = $editor['library path'] . '/js/etherpad.js';
  drupal_add_js($js);

  $ether_mod = drupal_get_path('module', 'etherpad');
  drupal_add_css($ether_mod . '/css/etherpad.css', array('absolute' => TRUE));
  /**
   * TODO: just a STUB
   */
  return array('default');
}

/**
 * Perform additional actions upon loading this editor.
 *
 * @param $editor
 *   A processed hook_editor() array of editor properties.
 * @param $library
 *   The internal library name (array key) to use.
 */
function etherpad_etherpad_lite_load($editor, $library) {
}

/**
 * Return runtime editor settings for a given wysiwyg profile.
 *
 * @param $editor
 *   A processed hook_editor() array of editor properties.
 * @param $config
 *   An array containing wysiwyg editor profile settings.
 * @param $theme
 *   The name of a theme/GUI/skin to use.
 *
 * @return
 *   A settings array to be populated in
 *   Drupal.settings.wysiwyg.configs.{editor}
 */
function etherpad_etherpad_lite_settings($editor, $config, $theme) {
  global $user;

  $settings = array();
  $settings['jspath'] = url('<front>') . $editor['library path'];
  $settings['host'] = variable_get('etherpad_base_url', 'http://localhost:9001');
  $settings['user'] = isset($user->name) ? $user->name : 'anonymous';

  return $settings;
}

function etherpad_etherpad_lite_plugins($editor) {
  return array(
    'default' => array(
      //'buttons' => $plugins,
      'internal' => TRUE,
    ),
  );
}