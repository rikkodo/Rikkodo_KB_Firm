// Copyright 2020 QMK / Sendy YK
// SPDX-License-Identifier: GPL-2.0-or-later/

#include QMK_KEYBOARD_H
#include "libRkd/keys/rkd_custom_keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [0] = LAYOUT(
        KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,     KC_7,      KC_8,       KC_9,      KC_0,      KC_MINS,   KC_EQL,  KC_BSPC,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,     KC_U,      KC_I,       KC_O,      KC_P,      KC_LBRC,   KC_RBRC, KC_BSLS,
        LT(3,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,     KC_J,      KC_K,       KC_L,      KC_SCLN,   KC_QUOT,            KC_ENT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,     KC_M,      KC_COMM,    KC_DOT,    KC_SLSH,   KC_RSFT,   KC_UP,   KC_RCTL,
        KC_LCTL,       KC_LALT, KC_LGUI, KC_BSPC, KC_SPC,  MT(MOD_LGUI,KC_ENT), KC_MS_BTN1, KC_MS_BTN2, KC_ENT,   KC_DEL,                KC_RGUI,   KC_RALT,   KC_LEFT,   KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        GRAVE_TILDA,   KC_1,    TWO_AT,  KC_3,    KC_4,    KC_5,                                        SIX_HAT,  SEVEN_AMP, EIGHT_STAR, NINE_LPAR, ZERO_RPAR, MIN_UNDER, EQ_PLUS,  KC_BSPC,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,     KC_U,      KC_I,       KC_O,      KC_P,      KC_RBRC,   KC_BSLS,  KC_INT3,
        LT(3,KC_GRV),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,     KC_J,      KC_K,       KC_L,      SCLN_COLN, QUOT_DQUO, KC_ENT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,     KC_M,      KC_COMM,    KC_DOT,    KC_SLSH,   KC_RSFT,   KC_UP,    KC_RCTL,
        KC_LCTL,       KC_LALT, KC_LGUI, KC_BSPC, KC_SPC,  MT(MOD_LGUI,KC_ENT), KC_MS_BTN1, KC_MS_BTN2, KC_ENT,   KC_DEL,                           KC_RGUI,   KC_RALT,   KC_LEFT,   KC_DOWN,  KC_RGHT
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT(
    //  GRAVE_TILDA,   KC_1,    TWO_AT,  KC_3,    KC_4,    KC_5,                                        SIX_HAT,  SEVEN_AMP, EIGHT_STAR, NINE_LPAR, ZERO_RPAR, MIN_UNDER, EQ_PLUS,  KC_BSPC,
        KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,    KC_F7,     KC_F8,      KC_F9,     KC_F10,    KC_F11,    KC_F12,   KC_DEL,
        KC_CAPS,       KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_PSLS,                                     KC_7,     KC_8,      KC_9,       KC_PSCR,   KC_SCRL,   KC_PAUS,   KC_RSFT,  KC_APP,
        KC_TRNS,       KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PAST,                                     KC_4,     KC_5,      KC_6,       KC_INS,    KC_HOME,   KC_PGUP,   KC_ENT,
        KC_LSFT,       TG(1),   KC_LNUM, KC_PPLS, KC_PMNS, KC_PDOT,                                     KC_1,     KC_2,      KC_3,       KC_DEL,    KC_END,    KC_PGDN,   KC_UP,    KC_RCTL,
        KC_LCTL,       KC_LALT, KC_LGUI, KC_LNG1, KC_LNG2, MT(MOD_LGUI,KC_ENT), KC_MS_BTN1, KC_MS_BTN3, KC_0,     KC_DOT,                KC_RGUI,   KC_RALT,   KC_LEFT,   KC_DOWN,  KC_RGHT
    ),
    // clang-format on
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [0] = {
        ENCODER_CCW_CW(RE_BS_BACKTAB, RE_SP_TAB),
    },
    [1] = {
        ENCODER_CCW_CW(RE_BS_BACKTAB, RE_SP_TAB),
    },
    [2] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    },
    [3] = {
        ENCODER_CCW_CW(RE_LEFT_UP, RE_RIGHT_DOWN),
    },
    // clang-format on
};
#endif