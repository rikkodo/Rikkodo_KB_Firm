// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A   , KC_B   , KC_C   , KC_D   , KC_E   ,
        KC_F   , KC_G   , KC_H   , KC_I   , KC_J   ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
        ENCODER_CCW_CW(KC_H   , KC_I   ),
        ENCODER_CCW_CW(KC_J   , KC_K   ),
        ENCODER_CCW_CW(KC_L   , KC_M   ),
        ENCODER_CCW_CW(KC_N   , KC_O   ),
        ENCODER_CCW_CW(KC_P   , KC_Q   ),
    },
    [1] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
    },
    [2] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
    },
    [3] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
    },
};
#endif
