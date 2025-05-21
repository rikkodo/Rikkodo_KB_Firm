#include QMK_KEYBOARD_H
#include "rkd_led_oled.h"

// LED状態のPrint SilverBulletのパクリ
extern rgblight_config_t rgblight_config;
rgblight_config_t rgblight_config_bak;
bool oled_led_stat(void)
{
    static char led_buf[48] = "LED state ready.\n";
    if (rgblight_config_bak.enable != rgblight_config.enable ||
        rgblight_config_bak.mode != rgblight_config.mode ||
        rgblight_config_bak.hue != rgblight_config.hue ||
        rgblight_config_bak.sat != rgblight_config.sat ||
        rgblight_config_bak.val != rgblight_config.val ||
        rgblight_config_bak.speed != rgblight_config.speed)
    {
        snprintf(led_buf, sizeof(led_buf) - 1, "Hue:%3d Sat:%3d\nVal:%3d Spd:%3d",
                 rgblight_config.hue,
                 rgblight_config.sat,
                 rgblight_config.val,
                 rgblight_config.speed);
        rgblight_config_bak = rgblight_config;
    }

    oled_write("LEDMode: ", false);
    static char led_modes[][12] = {
        "Static",
        "Breath1",
        "Breath2",
        "Breath3",
        "Breath4",
        "Mood1",
        "Mood2",
        "Mood3",
        "Swirl1",
        "Swirl2",
        "Swirl3",
        "Swirl4",
        "Swirl5",
        "Swirl6",
        "Snake1",
        "Snake2",
        "Snake3",
        "Snake4",
        "Snake5",
        "Snake6",
        "Knight1",
        "Knight2",
        "Knight3",
        "Chistmas",
        "Gradient1",
        "Gradient2",
        "Gradient3",
        "Gradient4",
        "Gradient5",
        "Gradient6",
        "Gradient7",
        "Gradient8",
        "Gradient9",
        "GradientA",
        "RGB Test",
        "Twinkle1",
        "Twinkle2",
        "Twinkle3",
        "Twinkle4",
        "Twinkle5",
        "Twinkle6",
    };
    oled_write(led_modes[rgblight_config.mode - 1], false);
    oled_write("\n", false);
    oled_write(led_buf, false);

    return false;
}
