/* Copyright 2023 projectcain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _BASE,
    _LOWER,
    _HIGHER,
    _ADJUST,
};

#define LOWER LT(_LOWER, KC_SPC)
#define HIGHER LT(_HIGHER, KC_BSPC)
#define ADJUST MO(_ADJUST)
#define LS LSFT_T
#define RS RSFT_T
#define S LSFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(

    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MPLY,
    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       RS(KC_SCLN),
    LS(KC_Z),   KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_ENT,
                        KC_LCTL,    KC_LGUI,    LOWER,     XXXXXXX,   HIGHER,   KC_LALT,     _______
  ),

  [_LOWER] = LAYOUT(

    S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),   S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),   _______,
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      XXXXXXX,   KC_MINS,    KC_EQUAL,   KC_LBRC,    KC_RBRC,    KC_QUOT,
    LS(KC_TAB), KC_F4,      KC_F5,      KC_F6,      XXXXXXX,   KC_DEL,     XXXXXXX,    XXXXXXX,    KC_SLSH,    _______,
                        _______,   _______,   _______,   _______,   ADJUST,   _______,   _______
  ),

  [_HIGHER] = LAYOUT(

    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    S(KC_1),    KC_F7,      KC_F8,      KC_F9,      XXXXXXX,   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_BSLS,
    LS(KC_TAB), KC_F10,     KC_F11,     KC_F12,     XXXXXXX,   XXXXXXX,   KC_MPRV,    KC_MPLY,    KC_MNXT,    _______,
                        _______,   _______,   ADJUST,   _______,   _______,   _______,   _______

  ),

  [_ADJUST] = LAYOUT(

    QK_BOOT,    KC_ACL0,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_BTN1,    KC_BTN3,    KC_BTN2,    KC_WH_U,    RGB_TOG,
    RGB_TOG,    KC_ACL1,    XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_WH_D,
    RGB_MOD,    KC_ACL2,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    _______,
                        _______,   _______,   _______,   _______,   _______,   _______,   _______

  ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
    [1] =   { ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
    [2] =   { ENCODER_CCW_CW(KC_MNXT, KC_MPRV)  },
    [3] =   { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)  },
};
#endif

