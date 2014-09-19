<?php
/**
 * @file
 * tf_migi.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function tf_migi_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: features.
  $menus['features'] = array(
    'menu_name' => 'features',
    'title' => 'Features',
    'description' => 'Menu items for any enabled features.',
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => '主選單',
    'description' => '<em>主</em>選單在多數網站用於顯示網站的主要部分，往往位於頂部導航欄。',
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => '<em>管理</em>選單包含管理任務的連結。',
  );
  // Exported menu: menu-movie-categories.
  $menus['menu-movie-categories'] = array(
    'menu_name' => 'menu-movie-categories',
    'title' => '影片分類',
    'description' => '',
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => '導覽',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => '<em>使用者</em>選單包含與使用者帳戶有關的連結，以及「登出」連結。',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('<em>主</em>選單在多數網站用於顯示網站的主要部分，往往位於頂部導航欄。');
  t('<em>使用者</em>選單包含與使用者帳戶有關的連結，以及「登出」連結。');
  t('<em>管理</em>選單包含管理任務的連結。');
  t('Features');
  t('Management');
  t('Menu items for any enabled features.');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('User menu');
  t('主選單');
  t('導覽');
  t('影片分類');


  return $menus;
}
