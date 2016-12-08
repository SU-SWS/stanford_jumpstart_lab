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


    /* Display: Members Page */
    $handler = $view->new_display('page', 'Members Page', 'members_page');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['grouping'] = array(
      0 => array(
        'field' => 'field_s_person_affiliation',
        'rendered' => 1,
        'rendered_strip' => 0,
      ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Nid */
    $handler->display->display_options['fields']['nid']['id'] = 'nid';
    $handler->display->display_options['fields']['nid']['table'] = 'node';
    $handler->display->display_options['fields']['nid']['field'] = 'nid';
    $handler->display->display_options['fields']['nid']['label'] = '';
    $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
    /* Field: Content: Profile Picture */
    $handler->display->display_options['fields']['field_s_person_profile_picture']['id'] = 'field_s_person_profile_picture';
    $handler->display->display_options['fields']['field_s_person_profile_picture']['table'] = 'field_data_field_s_person_profile_picture';
    $handler->display->display_options['fields']['field_s_person_profile_picture']['field'] = 'field_s_person_profile_picture';
    $handler->display->display_options['fields']['field_s_person_profile_picture']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_profile_picture']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_profile_picture']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_profile_picture']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_s_person_profile_picture']['settings'] = array(
      'image_style' => 'sm-square',
      'image_link' => 'content',
    );
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Content: Staff Type */
    $handler->display->display_options['fields']['field_s_person_staff_type']['id'] = 'field_s_person_staff_type';
    $handler->display->display_options['fields']['field_s_person_staff_type']['table'] = 'field_data_field_s_person_staff_type';
    $handler->display->display_options['fields']['field_s_person_staff_type']['field'] = 'field_s_person_staff_type';
    $handler->display->display_options['fields']['field_s_person_staff_type']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_staff_type']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_staff_type']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_staff_type']['type'] = 'taxonomy_term_reference_plain';
    $handler->display->display_options['fields']['field_s_person_staff_type']['delta_offset'] = '0';
    /* Field: Content: Title and Department */
    $handler->display->display_options['fields']['field_s_person_faculty_title']['id'] = 'field_s_person_faculty_title';
    $handler->display->display_options['fields']['field_s_person_faculty_title']['table'] = 'field_data_field_s_person_faculty_title';
    $handler->display->display_options['fields']['field_s_person_faculty_title']['field'] = 'field_s_person_faculty_title';
    $handler->display->display_options['fields']['field_s_person_faculty_title']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_faculty_title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_faculty_title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_limit'] = '3';
    $handler->display->display_options['fields']['field_s_person_faculty_title']['delta_offset'] = '0';
    /* Field: Content: Office */
    $handler->display->display_options['fields']['field_s_person_office_location']['id'] = 'field_s_person_office_location';
    $handler->display->display_options['fields']['field_s_person_office_location']['table'] = 'field_data_field_s_person_office_location';
    $handler->display->display_options['fields']['field_s_person_office_location']['field'] = 'field_s_person_office_location';
    $handler->display->display_options['fields']['field_s_person_office_location']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_office_location']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_office_location']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_office_location']['alter']['text'] = '<div><span class="descriptor">Office: </span>[field_s_person_office_location] </div>';
    $handler->display->display_options['fields']['field_s_person_office_location']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_office_location']['group_column'] = '';
    /* Field: Content: Office Hours */
    $handler->display->display_options['fields']['field_s_person_office_hours']['id'] = 'field_s_person_office_hours';
    $handler->display->display_options['fields']['field_s_person_office_hours']['table'] = 'field_data_field_s_person_office_hours';
    $handler->display->display_options['fields']['field_s_person_office_hours']['field'] = 'field_s_person_office_hours';
    $handler->display->display_options['fields']['field_s_person_office_hours']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_office_hours']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_office_hours']['alter']['text'] = '<div><span class="descriptor">Office Hours: </span>[field_s_person_office_hours] </div>';
    $handler->display->display_options['fields']['field_s_person_office_hours']['element_label_colon'] = FALSE;
    /* Field: Content: Phone */
    $handler->display->display_options['fields']['field_s_person_phone_display']['id'] = 'field_s_person_phone_display';
    $handler->display->display_options['fields']['field_s_person_phone_display']['table'] = 'field_data_field_s_person_phone_display';
    $handler->display->display_options['fields']['field_s_person_phone_display']['field'] = 'field_s_person_phone_display';
    $handler->display->display_options['fields']['field_s_person_phone_display']['label'] = 'Office Phone';
    $handler->display->display_options['fields']['field_s_person_phone_display']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_phone_display']['alter']['text'] = '<div><span class="descriptor">Phone: </span>[field_s_person_phone_display]</div>';
    /* Field: Content: Email */
    $handler->display->display_options['fields']['field_s_person_email']['id'] = 'field_s_person_email';
    $handler->display->display_options['fields']['field_s_person_email']['table'] = 'field_data_field_s_person_email';
    $handler->display->display_options['fields']['field_s_person_email']['field'] = 'field_s_person_email';
    $handler->display->display_options['fields']['field_s_person_email']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_email']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_email']['alter']['text'] = '<div><span class="descriptor">Email: </span>[field_s_person_email]</div>';
    /* Field: Content: Edit link */
    $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['label'] = '';
    $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
    $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<div class="edit-link">Edit</div>';
    $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
    /* Field: Global: View Rewrite */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: View Rewrite';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="postcard-left">
<div class="postcard-col1">
<div> [field_s_person_profile_picture]</div>

</div>

<div class="postcard-col2">
<h3>[title] </h3>
<div class="title-dept"> [field_s_person_faculty_title]</div>
[field_s_person_office_location]
[field_s_person_office_hours]
[field_s_person_phone_display]
[field_s_person_email]
<span class="edit-link">[edit_node]</span>
</div>

</div>';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Field: Content: Affiliation */
    $handler->display->display_options['fields']['field_s_person_affiliation']['id'] = 'field_s_person_affiliation';
    $handler->display->display_options['fields']['field_s_person_affiliation']['table'] = 'field_data_field_s_person_affiliation';
    $handler->display->display_options['fields']['field_s_person_affiliation']['field'] = 'field_s_person_affiliation';
    $handler->display->display_options['fields']['field_s_person_affiliation']['label'] = '';
    $handler->display->display_options['fields']['field_s_person_affiliation']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_s_person_affiliation']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_affiliation']['type'] = 'taxonomy_term_reference_plain';
    $handler->display->display_options['fields']['field_s_person_affiliation']['group_rows'] = FALSE;
    $handler->display->display_options['fields']['field_s_person_affiliation']['delta_offset'] = '0';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['path'] = 'people/members';

  }
}
