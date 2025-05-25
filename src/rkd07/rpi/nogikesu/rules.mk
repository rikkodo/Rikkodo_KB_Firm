ENCODER_MAP_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
I2C_DRIVER_REQUIRED = yes
POINTING_DEVICE_DRIVER = custom
OLED_ENABLE = yes
# Additional source libraries
SRC += libRkd/mouse/nogikesu/paw3222.c
SRC += libRkd/mouse/rkd_mouse.c