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

/**
 * @brief いずれかのModifierが押下されているか否かを返す
 *
 * @return true Yes
 * @return false No
 */
static bool _isAnyMod(void)
{
    return (keyboard_report->mods &
            (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI) |
             MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT) |
             MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)));
}

/**
 * @brief  RE_BS_BACKTABの処理
 *
 * @par MODキーが押下されており、Shiftが押下されている場合:  MOD+LEFT<br>
 *      MODキーが押下されており、Shiftが押下されていない場合: MOD+Shift+Tab<br>
 *      MODキーが押下されておらず、Shiftが押下されている場合: Shift+Space<br>
 *      MODキーが押下されておらず、Shiftが押下されていない場合: BS<br>
 *
 */
static void _process_RE_BS_BACKTAB(void)
{
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); // 左シフトが押されているかどうか
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); // 右シフトが押されているかどうか
    if (_isAnyMod())
    {
        // Modキーあり
        if (lshift || rshift)
        {
            // シフトあり
            if (lshift)
                unregister_code(KC_LSFT);
            if (rshift)
                unregister_code(KC_RSFT);
            tap_code16(KC_LEFT);
            if (lshift)
                register_code(KC_LSFT);
            if (rshift)
                register_code(KC_RSFT);
        }
        else
        {
            register_code(KC_LSFT);
            tap_code16(KC_TAB);
            unregister_code(KC_LSFT);
        }
    }
    else
    {
        // Modキーなし
        if (lshift || rshift)
        {
            // シフトあり
            tap_code16(KC_SPC);
        }
        else
        {
            // シフトなし
            tap_code16(KC_BSPC);
        }
    }
}
/**
 * @brief  RE_SP_TABの処理
 *
 * @par MODキーが押下されており、Shiftが押下されている場合: MOD + RIGHT (Shiftは外す)<br>
 *      MODキーが押下されており、Shiftが押下されていない場合: MOD + Tab<br>
 *      MODキーが押下されておらず、Shiftが押下されている場合: Enter (Shftは外す)<br>
 *      MODキーが押下されておらず、Shiftが押下されていない場合: Space<br>
 *
 */
static void _process_RE_SP_TAB(void)
{
    bool lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); // 左シフトが押されているかどうか
    bool rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); // 右シフトが押されているかどうか
    if (_isAnyMod())
    {
        // Modキーあり
        if (lshift || rshift)
        {
            // シフトあり
            if (lshift)
                unregister_code(KC_LSFT);
            if (rshift)
                unregister_code(KC_RSFT);
            tap_code16(KC_RIGHT);
            if (lshift)
                register_code(KC_LSFT);
            if (rshift)
                register_code(KC_RSFT);
        }
        else
        {
            tap_code16(KC_TAB);
        }
    }
    else
    {
        // Modキーなし
        if (lshift || rshift)
        {
            if (lshift)
                unregister_code(KC_LSFT);
            if (rshift)
                unregister_code(KC_RSFT);
            // シフトあり
            tap_code16(KC_ENT);
            if (lshift)
                register_code(KC_LSFT);
            if (rshift)
                register_code(KC_RSFT);
        }
        else
        {
            // シフトなし
            tap_code16(KC_SPC);
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
            _process_RE_BS_BACKTAB();
            return false;
        case RE_SP_TAB:
            _process_RE_SP_TAB();
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