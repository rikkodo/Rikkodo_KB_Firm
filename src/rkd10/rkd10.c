#include QMK_KEYBOARD_H
#include "libRkd/led/rkd_led_oled.h"

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
    const char *n;
    bool l = false;

    // OLEDに表示する内容を上から実装していく
    // Layer
    switch (get_highest_layer(layer_state | default_layer_state))
    {
    case 1:
        n = PSTR("HUE");
        break;
    case 2:
        n = PSTR("SAT");
        break;
    case 3:
        n = PSTR("VAL");
        break;
    case 0:
    default:
        n = PSTR("KIND");
        break;
    }
    oled_write_P(PSTR("Layer: "), false);
    oled_write_P(n, l);
    oled_advance_page(true);

    return oled_led_stat();
}
#endif