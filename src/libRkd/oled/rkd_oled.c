#include QMK_KEYBOARD_H
#include "rkd_oled.h"

#ifndef LAYER_ZERO_NAME
#define LAYER_ZERO_NAME ("Default")
#endif

#ifndef LAYER_ONE_NAME
#define LAYER_ONE_NAME ("Fakejis")
#endif

#ifndef LAYER_TWO_NAME
#define LAYER_TWO_NAME ("Mouse")
#endif

#ifndef LAYER_THREE_NAME
#define LAYER_THREE_NAME ("Function")
#endif

bool oled_hello_world(void)
{
    // OLEDに表示する内容を上から実装していく
    oled_write_ln_P(PSTR("Hello, world!"), false);

    return false;
}

bool oled_state_info(void)
{
    uint8_t modifiers = get_mods();
    led_t led_state = host_keyboard_led_state();
    const char *n;

    // Layer
    switch (get_highest_layer(layer_state | default_layer_state))
    {
    case 0:
        n = PSTR(LAYER_ZERO_NAME);
        break;
    case 1:
        n = PSTR(LAYER_ONE_NAME);
        break;
    case 2:
        n = PSTR(LAYER_TWO_NAME);
        break;
    case 3:
        n = PSTR(LAYER_THREE_NAME);
        break;
    default:
        n = PSTR("Undefined");
        break;
    }
    oled_write_P(PSTR("Layer: "), false);
    oled_write_P(n, false);
    oled_advance_page(true);

    // led status
    oled_write_P(PSTR("Caps"), led_state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Num"), led_state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Scr"), led_state.scroll_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Cmp"), led_state.compose);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Kana"), led_state.kana);
    // oled_advance_page(true);

    // Modifier Info
    oled_write_P(PSTR("Ctrl"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Shift"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Opt"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Cmd"), (modifiers & MOD_MASK_GUI));
    oled_advance_page(true);

    return false;
}

#ifdef RKE_OLED_ROTATIN
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return RKE_OLED_ROTATIN;
}
#endif

#ifdef RKD_USE_DEFAULT_OLED
bool oled_task_user(void)
{
    // OLEDに表示する内容を上から実装していく
    return oled_state_info();
}
#endif