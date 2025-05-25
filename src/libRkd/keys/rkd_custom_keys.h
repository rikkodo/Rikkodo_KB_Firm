#pragma once
#include QMK_KEYBOARD_H
#include <stdlib.h>
#include <stdbool.h>

enum custom_keycodes
{
    // QK_USER == 0x7E40 on qmk_firmware/quantum/keycodes.h
    // 他の人のコードを邪魔しないように、0x7EA0から振っていく。
    SAFE_RANGE_HEAD = 0x7EA0 - 1,
    TWO_AT,      // 0x7EA0 2/@ | 2/[
    SIX_HAT,     // 0x7EA1 6/^ | 6/=
    SEVEN_AMP,   // 0x7EA2 7/& | 7/S(6)
    EIGHT_STAR,  // 0x7EA3 8/* | 8/S(')
    NINE_LPAR,   // 0x7EA4 9/( | 9/S(8)
    ZERO_RPAR,   // 0x7EA5 0/) | 0/S(9)
    MIN_UNDER,   // 0x7EA6 -/_ | -/S(INT_RO)
    EQ_PLUS,     // 0x7EA7 =/+ | S(-)/S(;)
    SCLN_COLN,   // 0x7EA8 ;/: | ;/'
    QUOT_DQUO,   // 0x7EA9 '/" | S(2)/S(7)
    GRAVE_TILDA, // 0x7EAA `/~ | S([)/S(=)

    // QK_USER_MAX                    = 0x7FFF
};

/**
 * @brief カスタムキーコードの消化
 *
 * @param keycode keycode
 * @param record kyerecord
 * @return true true
 * @return false false
 */
bool rkd_process_record_user(uint16_t keycode, keyrecord_t *record);