#include QMK_KEYBOARD_H
#include "lib/oled/rkd_oled.h"

/******************************************************************************
 * OLED
 ******************************************************************************/

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_180; // flips the display 180 degrees if offhand
}

bool oled_task_user(void)
{
    // OLEDに表示する内容を上から実装していく
    return oled_led_stat();
}
#endif