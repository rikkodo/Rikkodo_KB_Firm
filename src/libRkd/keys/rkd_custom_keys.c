#include "rkd_custom_keys.h"

static void process_fake_keys(uint16_t key_without_shift, bool shift_without_shift,
                              uint16_t key_with_shift, bool shift_with_shift,
                              keyrecord_t *record)
{
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); // 左シフトが押されているかどうか
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); // 右シフトが押されているかどうか
    if (lshift || rshift)
    {
        // 実キーボードがシフトOn
        if (!shift_with_shift && lshift)
            unregister_code(KC_LSFT);
        if (!shift_with_shift && rshift)
            unregister_code(KC_RSFT);
        tap_code16(key_with_shift);
        if (!shift_with_shift && lshift)
            register_code(KC_LSFT);
        if (!shift_with_shift && rshift)
            register_code(KC_RSFT);
    }
    else
    {
        if (shift_without_shift)
            register_code(KC_LSFT);
        tap_code16(key_without_shift);
        if (shift_without_shift)
            unregister_code(KC_LSFT);
    }
}

bool rkd_process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed)
    {
        switch (keycode)
        {
        case TWO_AT:
            process_fake_keys(KC_2, false, KC_LBRC, false, record);
            return false;
        case SIX_HAT:
            process_fake_keys(KC_6, false, KC_EQL, false, record);
            return false;
        case SEVEN_AMP:
            process_fake_keys(KC_7, false, KC_6, true, record);
            return false;
        case EIGHT_STAR:
            process_fake_keys(KC_8, false, KC_QUOT, true, record);
            return false;
        case NINE_LPAR:
            process_fake_keys(KC_9, false, KC_8, true, record);
            return false;
        case ZERO_RPAR:
            process_fake_keys(KC_0, false, KC_9, true, record);
            return false;
        case MIN_UNDER:
            process_fake_keys(KC_MINS, false, KC_INT1, true, record);
            return false;
            return false;
        case EQ_PLUS:
            process_fake_keys(KC_MINS, true, KC_SCLN, true, record);
            return false;
        case SCLN_COLN:
            process_fake_keys(KC_SCLN, false, KC_QUOT, false, record);
            return false;
        case QUOT_DQUO:
            process_fake_keys(KC_7, true, KC_2, true, record);
            return false;
        case GRAVE_TILDA:
            process_fake_keys(KC_LBRC, true, KC_EQL, true, record);
            return false;
        default:
            break;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    return rkd_process_record_user(keycode, record);
}