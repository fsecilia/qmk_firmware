#include "process_record_user.h"
#include "lib/getreuer/features/socd_cleaner.h"

#define enable_socd
/* #define socd_enable_wasd */
#define socd_enable_sdfv

#if defined enable_socd

__attribute__((weak)) bool process_record_socd(uint16_t keycode, keyrecord_t *record) {
    static socd_cleaner_t cleaners[] = {

        #if defined socd_enable_wasd
            {{KC_W, KC_S}, SOCD_CLEANER_LAST},
            {{KC_A, KC_D}, SOCD_CLEANER_LAST},
        #endif

        #if defined socd_enable_sdfv
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
}

#else

__attribute__((weak)) bool process_record_socd(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#endif

__attribute__((weak)) bool process_record_layer_tap(uint16_t keycode, keyrecord_t *record) {
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

__attribute__((weak)) bool process_record_fsecilia(uint16_t keycode, keyrecord_t *record) {
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
