#include "rkd_custom_keys.h"

/**
 * @brief Shiftを含めたキーの変換処理
 *
 * @param key_without_shift シフトがおされていない時に送信するキーコード
 * @param shift_without_shift シフトがおされていない時に送信するシフト有無
 * @param key_with_shift シフトがおされている時に送信するキーコード
 * @param shift_with_shift シフトがおされていない時に送信するシフト有無
 */
static void _process_fake_keys(uint16_t key_without_shift, bool shift_without_shift,
                               uint16_t key_with_shift, bool shift_with_shift)
{
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); // 左シフトが押されているかどうか
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); // 右シフトが押されているかどうか
    if (lshift || rshift)
    {
        // 実キーボードがシフトOn
        lshift = lshift && !shift_with_shift;
        rshift = rshift && !shift_with_shift;
        if (lshift)
            unregister_code(KC_LSFT);
        if (rshift)
            unregister_code(KC_RSFT);
        tap_code16(key_with_shift);
        if (lshift)
            register_code(KC_LSFT);
        if (rshift)
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
            _process_fake_keys(KC_2, false, KC_LBRC, false);
            return false;
        case SIX_HAT:
            _process_fake_keys(KC_6, false, KC_EQL, false);
            return false;
        case SEVEN_AMP:
            _process_fake_keys(KC_7, false, KC_6, true);
            return false;
        case EIGHT_STAR:
            _process_fake_keys(KC_8, false, KC_QUOT, true);
            return false;
        case NINE_LPAR:
            _process_fake_keys(KC_9, false, KC_8, true);
            return false;
        case ZERO_RPAR:
            _process_fake_keys(KC_0, false, KC_9, true);
            return false;
        case MIN_UNDER:
            _process_fake_keys(KC_MINS, false, KC_INT1, true);
            return false;
            return false;
        case EQ_PLUS:
            _process_fake_keys(KC_MINS, true, KC_SCLN, true);
            return false;
        case SCLN_COLN:
            _process_fake_keys(KC_SCLN, false, KC_QUOT, false);
            return false;
        case QUOT_DQUO:
            _process_fake_keys(KC_7, true, KC_2, true);
            return false;
        case GRAVE_TILDA:
            _process_fake_keys(KC_LBRC, true, KC_EQL, true);
            return false;
        case RE_BS_BACKTAB:
            _process_fake_keys(KC_BSPC, false, KC_TAB, true);
            return false;
        case RE_SP_TAB:
            _process_fake_keys(KC_SPC, false, KC_TAB, false);
            return false;
        case RE_LEFT_UP:
            _process_fake_keys(KC_LEFT, false, KC_UP, false);
            return false;
        case RE_RIGHT_DOWN:
            _process_fake_keys(KC_RGHT, false, KC_DOWN, false);
            return false;
        default:
            break;
        }
    }
    return true;
}

#ifdef RKD_USE_DEFAULT_CUSTOM_KEYS
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    return rkd_process_record_user(keycode, record);
}
#endif