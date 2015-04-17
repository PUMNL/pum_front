<?php

$cc_reltype_id = civicrm_api3('RelationshipType', 'getvalue', array('name_a_b' => 'Country Coordinator is', 'return' => 'id'));
$rep_reltype_id = civicrm_api3('RelationshipType', 'getvalue', array('name_a_b' => 'Representative is', 'return' => 'id'));
$po_reltype_id = civicrm_api3('RelationshipType', 'getvalue', array('name_a_b' => 'Project Officer for', 'return' => 'id'));

$view = new view();
$view->name = 'site_country_experts';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_relationship';
$view->human_name = 'Site Country Experts';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Expert';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'description',
    'rendered' => 1,
    'rendered_strip' => 1,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'id' => 'id',
  'display_name' => 'display_name',
);
/* Relationship: CiviCRM Relationships: Contact ID A */
$handler->display->display_options['relationships']['contact_id_a_']['id'] = 'contact_id_a_';
$handler->display->display_options['relationships']['contact_id_a_']['table'] = 'civicrm_relationship';
$handler->display->display_options['relationships']['contact_id_a_']['field'] = 'contact_id_a_';
/* Relationship: CiviCRM Relationships: Contact ID B */
$handler->display->display_options['relationships']['contact_id_b_']['id'] = 'contact_id_b_';
$handler->display->display_options['relationships']['contact_id_b_']['table'] = 'civicrm_relationship';
$handler->display->display_options['relationships']['contact_id_b_']['field'] = 'contact_id_b_';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['display_name']['label'] = 'Expert';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Relationships: Start Date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['start_date']['custom_date_format'] = 'd-m-Y';
/* Field: CiviCRM Relationships: End Date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['end_date']['custom_date_format'] = 'd-m-Y';
/* Sort criterion: CiviCRM Relationships: Start Date */
$handler->display->display_options['sorts']['start_date']['id'] = 'start_date';
$handler->display->display_options['sorts']['start_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['sorts']['start_date']['field'] = 'start_date';
$handler->display->display_options['sorts']['start_date']['order'] = 'DESC';
/* Contextual filter: CiviCRM Custom: Country data: CountryID */
$handler->display->display_options['arguments']['civicrm_country_id']['id'] = 'civicrm_country_id';
$handler->display->display_options['arguments']['civicrm_country_id']['table'] = 'civicrm_value_country';
$handler->display->display_options['arguments']['civicrm_country_id']['field'] = 'civicrm_country_id';
$handler->display->display_options['arguments']['civicrm_country_id']['relationship'] = 'contact_id_a_';
$handler->display->display_options['arguments']['civicrm_country_id']['default_action'] = 'empty';
$handler->display->display_options['arguments']['civicrm_country_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['civicrm_country_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['civicrm_country_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['civicrm_country_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['filters']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['value'] = array(
  $rep_reltype_id => $rep_reltype_id,
);
/* Filter criterion: CiviCRM Relationships: Is Relationship Active */
$handler->display->display_options['filters']['is_active']['id'] = 'is_active';
$handler->display->display_options['filters']['is_active']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['is_active']['field'] = 'is_active';
$handler->display->display_options['filters']['is_active']['value'] = '1';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'sitecountry-experts';

/* Display: Block exp */
$handler = $view->new_display('block', 'Block exp', 'block');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';

/* Display: Block cc */
$handler = $view->new_display('block', 'Block cc', 'block_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['alter']['path'] = 'portal/directory/[id]';
$handler->display->display_options['fields']['display_name']['element_class'] = 'field-name-field-country-user-name';
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['email']['label'] = '';
$handler->display->display_options['fields']['email']['element_class'] = 'field-name-field-country-user-email';
$handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['email']['location_type'] = '2';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
$handler->display->display_options['fields']['email']['link_to_user'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['filters']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['value'] = array(
  $cc_reltype_id => $cc_reltype_id,
);
/* Filter criterion: CiviCRM Relationships: Is Relationship Active */
$handler->display->display_options['filters']['is_active']['id'] = 'is_active';
$handler->display->display_options['filters']['is_active']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['is_active']['field'] = 'is_active';
$handler->display->display_options['filters']['is_active']['value'] = '1';

/* Display: Block rep */
$handler = $view->new_display('block', 'Block rep', 'block_2');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'description',
    'rendered' => 0,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'id' => 'id',
  'display_name' => 'display_name',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Relationships: Description */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['description']['field'] = 'description';
$handler->display->display_options['fields']['description']['label'] = '';
$handler->display->display_options['fields']['description']['exclude'] = TRUE;
$handler->display->display_options['fields']['description']['element_class'] = 'field-name-field-repres-region';
$handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['element_wrapper_class'] = 'field-name-field-repres-person';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['email']['label'] = '';
$handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['email']['location_type'] = '2';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
$handler->display->display_options['fields']['email']['link_to_user'] = '0';
/* Field: CiviCRM Phone Details: Phone Number */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['phone']['label'] = '';
$handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['phone']['location_type'] = '2';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 0;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';

/* Display: Block po */
$handler = $view->new_display('block', 'Block po', 'block_3');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'id' => 'id',
  'display_name' => 'display_name',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['display_name']['label'] = '';
$handler->display->display_options['fields']['display_name']['element_class'] = 'field-name-field-country-user-name';
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['email']['label'] = '';
$handler->display->display_options['fields']['email']['element_class'] = 'field-name-field-country-user-email';
$handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['email']['location_type'] = '2';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
$handler->display->display_options['fields']['email']['link_to_user'] = '0';
/* Field: CiviCRM Relationships: Description */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['description']['field'] = 'description';
$handler->display->display_options['fields']['description']['label'] = '';
$handler->display->display_options['fields']['description']['exclude'] = TRUE;
$handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: CiviCRM Relationships: Relationship Type A-to-B */
$handler->display->display_options['filters']['relationship_type']['id'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['relationship_type']['field'] = 'relationship_type';
$handler->display->display_options['filters']['relationship_type']['value'] = array(
  $po_reltype_id => $po_reltype_id,
);
/* Filter criterion: CiviCRM Relationships: Is Relationship Active */
$handler->display->display_options['filters']['is_active']['id'] = 'is_active';
$handler->display->display_options['filters']['is_active']['table'] = 'civicrm_relationship';
$handler->display->display_options['filters']['is_active']['field'] = 'is_active';
$handler->display->display_options['filters']['is_active']['value'] = '1';
$translatables['site_country_experts'] = array(
  t('Master'),
  t('Expert'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('CiviCRM Contact A'),
  t('CiviCRM Contact B'),
  t('Start Date'),
  t('End Date'),
  t('All'),
  t('Page'),
  t('Block exp'),
  t('Block cc'),
  t('.'),
  t('Block rep'),
  t('Block po'),
);
