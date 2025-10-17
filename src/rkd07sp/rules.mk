ENCODER_MAP_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
I2C_DRIVER_REQUIRED = yes
OLED_ENABLE = yes
SERIAL_DRIVER = vendor
# Additional source libraries
SRC += libRkd/mouse/rkd_mouse.c
SRC += libRkd/keys/rkd_custom_keys.c
SRC += libRkd/oled/rkd_oled.c
