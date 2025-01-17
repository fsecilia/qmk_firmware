#include "process_record_user.h"
#include "lib/getreuer/features/socd_cleaner.h"

#define SOCD
/* #define SOCD_WASD */
#define SOCD_SDFV

bool process_record_socd(uint16_t keycode, keyrecord_t *record) {
#if !defined SOCD || !(defined SOCD_WASD || defined SOCD_SDFV)
    return true;
#else

    static socd_cleaner_t cleaners[] = {

#if defined SOCD_WASD
        {{KC_W, KC_S}, SOCD_CLEANER_LAST},
        {{KC_A, KC_D}, SOCD_CLEANER_LAST},
#endif

#if defined SOCD_SDFV
        {{KC_S, KC_F}, SOCD_CLEANER_LAST},
        {{KC_D, KC_V}, SOCD_CLEANER_LAST},
#endif

    };
    static int num_cleaners = sizeof(cleaners) / sizeof(*cleaners);

    /* only apply socd on topmost layer */
    bool on_top_layer = dynamic_keymap_get_layer_count() == layer_switch_get_layer(record->event.key) + 1;
    if (!on_top_layer) return true;

    for (int cleaner = 0; cleaner < num_cleaners; ++cleaner) {
        if (!process_socd_cleaner(keycode, record, &cleaners[cleaner])) {
            return false;
        }
    }

    return true;
#endif
}

bool process_record_layer_tap(uint16_t keycode, keyrecord_t *record) {
    bool is_tap = (keycode & QK_LAYER_TAP) && record->event.pressed && record->tap.count;
    if (!is_tap) return true;

    uint16_t tap_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    switch (tap_keycode) {
        /* replace backspace tap with ctrl+backspace tap */
        case KC_BSPC:
            tap_code16(C(KC_BSPC));
            return false;
    }

    return true;
}

bool process_record_fsecilia(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_layer_tap(keycode, record)) {
        return false;
    }

    if (!process_record_socd(keycode, record)) {
        return false;
    }

    return true;
}

__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fsecilia(keycode, record)) {
        return false;
    }

    return true;
}
