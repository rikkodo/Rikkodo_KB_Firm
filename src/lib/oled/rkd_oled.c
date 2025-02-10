#include QMK_KEYBOARD_H
#include "rkd_oled.h"

bool oled_hello_world(void)
{
    // OLEDに表示する内容を上から実装していく
    oled_write_ln_P(PSTR("Hello, world!"), false);

    return false;
}