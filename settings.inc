<?php
// $Id$

function pspicefile_settings_form($form_state)
{
    $form['emails'] = array(
        '#type' => 'textfield',
        '#title' => t('(Bcc) Notification emails'),
        '#description' => t('Specify emails id for Bcc option of mail system with comma separated'),
        '#size' => 50,
        '#maxlength' => 255,
        '#required' => true,
        '#default_value' => variable_get('kicad_emails', ''),
    );

    $form['cc_emails'] = array(
        '#type' => 'textfield',
        '#title' => t('(Cc) Notification emails'),
        '#description' => t('Specify emails id for Cc option of mail system with comma separated'),
        '#size' => 50,
        '#maxlength' => 255,
        '#required' => true,
        '#default_value' => variable_get('kicad_cc_emails', ''),
    );

    $form['from_email'] = array(
        '#type' => 'textfield',
        '#title' => t('Outgoing from email address'),
        '#description' => t('Email address to be display in the from field of all outgoing messages'),
        '#size' => 50,
        '#maxlength' => 255,
        '#required' => true,
        '#default_value' => variable_get('kicad_from_email', ''),
    );
    $form['extensions']['pspicefile'] = array(
        '#type' => 'textfield',
        '#title' => t('Allowed pspice file extensions'),
        '#description' => t('A comma separated list WITHOUT SPACE of source file extensions that are permitted to be uploaded on the server'),
        '#size' => 50,
        '#maxlength' => 255,
        '#required' => true,
        '#default_value' => variable_get('pspice_files_extensions', ''),
    );
    $form['extensions']['kicadcorrectedfile'] = array(
        '#type' => 'textfield',
        '#title' => t('Allowed Kicad corrected file extensions'),
        '#description' => t('A comma separated list WITHOUT SPACE of source file extensions that are permitted to be uploaded on the server'),
        '#size' => 50,
        '#maxlength' => 255,
        '#required' => true,
        '#default_value' => variable_get('kicad_corrected_files_extensions', ''),
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit'),
    );
    return $form;
}

function pspicefile_settings_form_validate($form, &$form_state)
{
    return;
}

function pspicefile_settings_form_submit($form, &$form_state)
{
    variable_set('kicad_emails', $form_state['values']['emails']);
    variable_set('kicad_cc_emails', $form_state['values']['cc_emails']);
    variable_set('kicad_from_email', $form_state['values']['from_email']);
    variable_set('pspice_files_extensions', $form_state['values']['pspicefile']);
    variable_set('kicad_corrected_files_extensions', $form_state['values']['kicadcorrectedfile']);
    drupal_set_message(t('Settings updated'), 'status');
}
