#include "process_record_user.h"

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

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fsecilia(keycode, record)) {
        return false;
    }

    return true;
}
