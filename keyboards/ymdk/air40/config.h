
#pragma once
#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID       0x45D4
#define PRODUCT_ID      0x0911
#define DEVICE_VER      0x0001
#define MANUFACTURER    MT
#define PRODUCT         Air40
#define DESCRIPTION     Air40rgb

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D0, B3, B2, B1 }
#define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW



#define DYNAMIC_KEYMAP_LAYER_COUNT 3
#define DYNAMIC_KEYMAP_MACRO_COUNT 3
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 7
/* prevent stuck modifiers */

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
#define DRIVER_LED_TOTAL 55
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 70
#define RGB_MATRIX_CENTER { 112, 32 }
#endif


#define VIAL_KEYBOARD_UID {0x54, 0xF8, 0x27, 0x15, 0x2B, 0x66, 0x3A, 0xC0}