#pragma once

#include "process_record_user.h"

/* hijack LT(0, <kc>) as something we can edit in via and override here, without needing named keys in via */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0, KC_BKSP):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(keycode));
                return false;
            }
            break;
    }

    return true;
}
