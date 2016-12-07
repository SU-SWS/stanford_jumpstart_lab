<?php
/**
 * @file
 * Default views alter.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function stanford_jumpstart_lab_views_default_views_alter(&$views) {
  if (isset($views['stanford_person_staff'])) {
    $view = &$views['stanford_person_staff'];

    $term = reset(taxonomy_get_term_by_name('Alumni', 'stanford_affiliation'));
    if ($term) {
      /* Display: Alumni Page */
      $handler = $view->new_display('page', 'Alumni Page', 'alumni_page');
      $handler->display->display_options['defaults']['title'] = FALSE;
      $handler->display->display_options['title'] = 'Alumni';
      $handler->display->display_options['defaults']['relationships'] = FALSE;
      $handler->display->display_options['defaults']['arguments'] = FALSE;
      $handler->display->display_options['defaults']['filter_groups'] = FALSE;
      $handler->display->display_options['defaults']['filters'] = FALSE;
      /* Filter criterion: Content: Published */
      $handler->display->display_options['filters']['status']['id'] = 'status';
      $handler->display->display_options['filters']['status']['table'] = 'node';
      $handler->display->display_options['filters']['status']['field'] = 'status';
      $handler->display->display_options['filters']['status']['value'] = 1;
      $handler->display->display_options['filters']['status']['group'] = 1;
      $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
      /* Filter criterion: Content: Type */
      $handler->display->display_options['filters']['type']['id'] = 'type';
      $handler->display->display_options['filters']['type']['table'] = 'node';
      $handler->display->display_options['filters']['type']['field'] = 'type';
      $handler->display->display_options['filters']['type']['value'] = array(
        'stanford_person' => 'stanford_person',
      );
      $handler->display->display_options['filters']['type']['group'] = 1;
      /* Filter criterion: Content: Title */
      $handler->display->display_options['filters']['title']['id'] = 'title';
      $handler->display->display_options['filters']['title']['table'] = 'node';
      $handler->display->display_options['filters']['title']['field'] = 'title';
      $handler->display->display_options['filters']['title']['operator'] = 'contains';
      $handler->display->display_options['filters']['title']['group'] = 1;
      $handler->display->display_options['filters']['title']['exposed'] = TRUE;
      $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
      $handler->display->display_options['filters']['title']['expose']['label'] = 'Search staff by name';
      $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
      $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
      $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
        2 => '2',
        1 => 0,
        13 => 0,
        11 => 0,
        9 => 0,
        7 => 0,
        5 => 0,
      );
      /* Filter criterion: Content: Staff Type (field_s_person_staff_type) */
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['id'] = 'field_s_person_staff_type_tid';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['table'] = 'field_data_field_s_person_staff_type';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['field'] = 'field_s_person_staff_type_tid';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['exposed'] = TRUE;
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator_id'] = 'field_s_person_staff_type_tid_op';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['label'] = 'Filter by staff type';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['operator'] = 'field_s_person_staff_type_tid_op';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['expose']['identifier'] = 'field_s_person_staff_type_tid';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['type'] = 'select';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['vocabulary'] = 'stanford_staff_type';
      $handler->display->display_options['filters']['field_s_person_staff_type_tid']['hierarchy'] = 1;
      /* Filter criterion: Content: Affiliation (field_s_person_affiliation) */
      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['id'] = 'field_s_person_affiliation_tid';
      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['table'] = 'field_data_field_s_person_affiliation';
      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['field'] = 'field_s_person_affiliation_tid';

      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['value'] = array(
        $term->tid => "$term->tid",
      );

      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['type'] = 'select';
      $handler->display->display_options['filters']['field_s_person_affiliation_tid']['vocabulary'] = 'stanford_affiliation';
      $handler->display->display_options['path'] = 'people/alumni';
    }
  }
}
