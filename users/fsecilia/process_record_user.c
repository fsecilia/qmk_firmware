#include "process_record_user.h"

bool process_record_layer_tap(uint16_t tap_keycode, keyrecord_t *record) {
    bool replace_tap = record->event.pressed && record->tap.count;
    if (!replace_tap) return true;

    switch (tap_keycode) {
        /* replace backspace tap with ctrl+backspace tap */
        case KC_BSPC:
            tap_code16(C(KC_BSPC));
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if ((keycode & QK_LAYER_TAP) && !process_record_layer_tap(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode), record)) {
        return false;
    }

    return true;
}
