// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1)),
    [1] = LAYOUT(
        TO(2)),
    [2] = LAYOUT(
        TO(3)),
    [3] = LAYOUT(
        TO(4)),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
        ENCODER_CCW_CW(UG_NEXT, UG_PREV),
    },
    [1] = {
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
    },
    [2] = {
        ENCODER_CCW_CW(UG_SATU, UG_SATD),
    },
    [3] = {
        ENCODER_CCW_CW(UG_VALU, UG_VALD),
    },
};
#endif
