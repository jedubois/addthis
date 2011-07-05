<?php

/**
 * @file
 * Administrative page callbacks for the AddThis-module.
 */
 
/**
 * Implements hook_admin_settings_form().
 */
function addthis_admin_settings_form($form_state) {
  AddThis::addStylesheets();
  $form[AddThis::PROFILE_ID_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis Profile ID'),
    '#default_value' => AddThis::getProfileId(),
    '#required' => FALSE,
    '#description' => t('Profile ID at <a href="http://addthis.com/" target="_blank">AddThis.com</a>. Required for statistics.'),
  );
  $form['visual_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visual settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['visual_settings_fieldset'][AddThis::LARGE_ICONS_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use large toolbox icons'),
    '#default_value' => AddThis::areLargeIconsEnabled(),
    '#required' => FALSE,
    '#description' => t('Use large 32x32 pixel toolbox icons instead of smaller 16x16 pixel icons.'),
  );
  $form['visual_settings_fieldset'][AddThis::UI_HEADER_COLOR_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis user interface header text color'),
    '#default_value' => AddThis::getUiHeaderColor(),
    '#required' => FALSE,
    '#description' => t('AddThis user interface header text color (like #ffffff).'),
  );
  $form['visual_settings_fieldset'][AddThis::UI_HEADER_BACKGROUND_COLOR_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis user interface header background color'),
    '#default_value' => AddThis::getUiHeaderBackgroundColor(),
    '#required' => FALSE,
    '#description' => t('AddThis user interface header background color (like #000000).'),
  );
  $form['service_urls_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Service URLs'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['service_urls_fieldset'][AddThis::BOOKMARK_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis bookmark URL'),
    '#default_value' => AddThis::getBaseBookmarkUrl(),
    '#required' => TRUE,
    '#description' => t('AddThis bookmark URL.'),
  );
  $form['service_urls_fieldset'][AddThis::SERVICES_CSS_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis services stylesheet URL'),
    '#default_value' => AddThis::getServicesCssUrl(),
    '#required' => TRUE,
    '#description' => t('AddThis services stylesheet URL.'),
  );
  $form['service_urls_fieldset'][AddThis::SERVICES_JSON_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis services json URL'),
    '#default_value' => AddThis::getServicesJsonUrl(),
    '#required' => TRUE,
    '#description' => t('AddThis services json URL.'),
  );
  $form['service_urls_fieldset'][AddThis::WIDGET_JS_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis javascript widget URL'),
    '#default_value' => AddThis::getBaseWidgetJsUrl(),
    '#required' => TRUE,
    '#description' => t('AddThis javascript widget URL.'),
  );
  $form['enabled_services_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled services'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['enabled_services_fieldset'][AddThis::ENABLED_SERVICES_KEY] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled services'),
    '#options' => AddThis::getServiceOptions(),
    '#default_value' => AddThis::getEnabledServiceOptions(),
    '#required' => FALSE,
    '#description' => t('Check enabled services.'),
  );
  $form['advanced_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#access' => user_access(AddThis::PERMISSION_ADMINISTER_ADVANCED_ADDTHIS),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced_settings_fieldset'][AddThis::CUSTOM_CONFIGURATION_CODE_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use custom AddThis configuration code'),
    '#default_value' => AddThis::isCustomConfigurationCodeEnabled(),
    '#required' => FALSE,
    '#description' => t('Use custom AddThis configuration code. If checked, custom configuration will be used instead of other configuration settings provided in AddThis administration user interface. Note that the Profile ID (pubid) will not be overwritten by custom configuration code.'),
  );
  $form['advanced_settings_fieldset'][AddThis::CUSTOM_CONFIGURATION_CODE_KEY] = array(
    '#type' => 'textarea',
    '#title' => t('AddThis custom configuration code'),
    '#default_value' => AddThis::getCustomConfigurationCode(),
    '#required' => FALSE,
    '#description' => t('AddThis custom configuration code. See format at <a href="http://addthis.com/" target="_blank">AddThis.com</a>'),
  );
  return system_settings_form($form);
}