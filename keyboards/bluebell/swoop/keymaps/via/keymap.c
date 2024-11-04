/* Copyright 2022 James White <jamesmnw@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it wbill be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers { QWERTY, OPTIMIZED, NUM, SYM, FUN, NAV };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

[QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,   KC_W,    KC_E,            KC_R,    KC_T,               KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,    KC_D,            KC_F,    KC_G,               KC_H,   KC_J,    KC_K,    KC_L,    S(KC_MINS),
    KC_Z,   KC_X,    KC_C,            KC_V,    KC_B,               KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                     LT(NUM, KC_ESC), MO(NAV), OSM(MOD_LSFT),      QK_REP, KC_SPC,  LT(SYM, KC_ENT)
),

[OPTIMIZED] = LAYOUT_split_3x5_3(
    KC_Q,   KC_W,    KC_E,            KC_R,    KC_T,               KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,    KC_D,            KC_F,    KC_G,               KC_H,   KC_J,    KC_K,    KC_L,    S(KC_MINS),
    KC_Z,   KC_X,    KC_C,            KC_V,    KC_B,               KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                     LT(NUM, KC_ESC), MO(NAV), OSM(MOD_LSFT),      QK_REP, KC_SPC,  LT(SYM, KC_ENT)
),

[NAV] = LAYOUT_split_3x5_3(
    KC_F10,  KC_F11,        KC_F12,        KC_TAB,        S(KC_TAB),         KC_PGUP, C(KC_LEFT), KC_UP,   C(KC_RGHT), KC_PGDN,
    C(KC_A), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_F3,             KC_HOME, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_END,
    C(KC_Z), C(KC_X),       C(KC_C),       C(KC_V),       KC_LGUI,           KC_DEL,  C(KC_V),    C(KC_C), C(KC_X),    C(KC_Z),
                            KC_TRNS,       KC_TRNS,       KC_TRNS,           KC_TRNS, C(KC_BSPC), KC_BSPC
),

[NUM] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB,  S(KC_6),          KC_COMM,   KC_7, KC_8,    KC_9,   S(KC_8),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,           S(KC_EQL), KC_1, KC_2,    KC_3,   KC_MINS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_DOT,    KC_4, KC_5,    KC_6,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,   KC_0, LT(FUN, KC_ENT)
),

[SYM] = LAYOUT_split_3x5_3(
    S(KC_GRV),  S(KC_1),    S(KC_LBRC),      S(KC_RBRC), S(KC_6),        KC_NO,   S(KC_2),       KC_GRV,        S(KC_5),       KC_BSLS,
    KC_QUOT,    S(KC_SCLN), S(KC_9),         S(KC_0),    S(KC_BSLS),     S(KC_4), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), S(KC_6),
    S(KC_QUOT), KC_SCLN,    KC_LBRC,         KC_RBRC,    S(KC_7),        S(KC_3), KC_EQL,        S(KC_COMM),    S(KC_DOT),     S(KC_SLSH),
                            LT(FUN, KC_ESC), KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS,       KC_TRNS
),

[FUN] = LAYOUT_split_3x5_3(
    KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_NO,
    OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO,          KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_NO,
    KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_NO,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
),

};
// clang-format on
