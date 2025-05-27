#include "rkd_custom_keys.h"

/**
 * @brief Shiftを含めたキーの変換処理
 *
 * @param key_without_shift シフトがおされていない時に送信するキーコード
 * @param shift_without_shift シフトがおされていない時に送信するシフト有無
 * @param key_with_shift シフトがおされている時に送信するキーコード
 * @param shift_with_shift シフトがおされていない時に送信するシフト有無
 */
static void process_fake_keys(uint16_t key_without_shift, bool shift_without_shift,
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

/**
 * @brief Modキーが押下されている場合に内容を切り替えるキーの変換処理
 *        ModキーはCtrl, Alt, Cmdを指すものとする
 *
 * @param key_without_mod MODキー無し時に送信するキーコード
 * @param shift_without_mod MODキー無し時に送信するシフト有無
 * @param invert_shift_without_mod MODキー無し時にShiftを透過させるか否か
 * @param key_with_mod MODキーあり時
 * @param shift_with_mod MODキーあり時
 * @param invert_shift_with_mod MODキーあり時
 */
static void process_mod_revert(uint16_t key_without_mod, bool shift_without_mod, bool invert_shift_without_mod,
                               uint16_t key_with_mod, bool shift_with_mod, bool invert_shift_with_mod)
{
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); // 左シフトが押されているかどうか
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); // 右シフトが押されているかどうか
    if (keyboard_report->mods &
        (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI) |
         MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT) |
         MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))
    {
        if (lshift || rshift)
        {
            lshift = lshift && !shift_with_mod && !invert_shift_with_mod;
            rshift = rshift && !shift_with_mod && !invert_shift_with_mod;
            if (lshift)
                unregister_code(KC_LSFT);
            if (rshift)
                unregister_code(KC_RSFT);
            tap_code16(key_with_mod);
            if (lshift)
                register_code(KC_LSFT);
            if (rshift)
                register_code(KC_RSFT);
        }
        else
        {
            if (shift_with_mod)
                register_code(KC_LSFT);
            tap_code16(key_with_mod);
            if (shift_with_mod)
                unregister_code(KC_LSFT);
        }
    }
    else
    {
        if (lshift || rshift)
        {
            lshift = lshift && !shift_without_mod && !invert_shift_without_mod;
            rshift = rshift && !shift_without_mod && !invert_shift_without_mod;
            if (lshift)
                unregister_code(KC_LSFT);
            if (rshift)
                unregister_code(KC_RSFT);
            tap_code16(key_with_mod);
            if (lshift)
                register_code(KC_LSFT);
            if (rshift)
                register_code(KC_RSFT);
        }
        else
        {
            if (shift_without_mod)
                register_code(KC_LSFT);
            tap_code16(key_without_mod);
            if (shift_without_mod)
                unregister_code(KC_LSFT);
        }
    }
}

bool rkd_process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed)
    {
        switch (keycode)
        {
        case TWO_AT:
            process_fake_keys(KC_2, false, KC_LBRC, false);
            return false;
        case SIX_HAT:
            process_fake_keys(KC_6, false, KC_EQL, false);
            return false;
        case SEVEN_AMP:
            process_fake_keys(KC_7, false, KC_6, true);
            return false;
        case EIGHT_STAR:
            process_fake_keys(KC_8, false, KC_QUOT, true);
            return false;
        case NINE_LPAR:
            process_fake_keys(KC_9, false, KC_8, true);
            return false;
        case ZERO_RPAR:
            process_fake_keys(KC_0, false, KC_9, true);
            return false;
        case MIN_UNDER:
            process_fake_keys(KC_MINS, false, KC_INT1, true);
            return false;
            return false;
        case EQ_PLUS:
            process_fake_keys(KC_MINS, true, KC_SCLN, true);
            return false;
        case SCLN_COLN:
            process_fake_keys(KC_SCLN, false, KC_QUOT, false);
            return false;
        case QUOT_DQUO:
            process_fake_keys(KC_7, true, KC_2, true);
            return false;
        case GRAVE_TILDA:
            process_fake_keys(KC_LBRC, true, KC_EQL, true);
            return false;
        case RE_BS_BACKTAB:
            process_mod_revert(KC_BSPC, false, false, KC_TAB, true, true);
            return false;
        case RE_SP_TAB:
            process_mod_revert(KC_SPC, false, false, KC_TAB, false, true);
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