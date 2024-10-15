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

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    HIGHER,
    ADJUST,
};

#define LS LSFT_T
#define RS RSFT_T
#define LW_SPC MT(LOWER, KC_SPC)
#define HI_BSPC MT(HIGHER, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(

    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       RS(KC_SCLN),
    LS(KC_Z),   KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_ENT,
                        KC_LGUI,    KC_LCTL,    LW_SPC,     XXXXXXXX,   HI_BSPC,   KC_LALT,     ________
  ),

  [_LOWER] = LAYOUT(

    LS(KC_1),   LS(KC_2),   LS(KC_3),   LS(KC_4),   LS(KC_5),   LS(KC_6),   LS(KC_7),   LS(KC_8),   LS(KC_9),   LS(KC_0),   _______,
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      XXXXXXXX,   KC_MINS,    KC_EQUAL,   KC_LBRC,    KC_RBRC,    KC_QUOT,
    LS(KC_TAB), KC_F4,      KC_F5,      KC_F6,      XXXXXXXX,   KC_DEL,     XXXXXXXX,   XXXXXXXX,   KC_SLSH,    _______,
                        ________,   ________,   ________,   XXXXXXXX,   ________,   ________,   ________
  ),

  [_HIGHER] = LAYOUT(

    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    S(KC_1),    KC_F7,      KC_F8,      KC_F9,      XXXXXXXX,   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_BSLS,
    LS(KC_TAB), KC_F10,     KC_F11,     KC_F12,     XXXXXXXX,   XXXXXXXX,   KC_MPRV,    KC_MPLY,    KC_MNXT,    ______,
                        ________,   ________,   ________,   XXXXXXXX,   ________,   ________,   ________

  ),

  [_ADJUST] = LAYOUT(

    QK_BOOT,    KC_ACL0,    XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   KC_BTN1,    KC_BTN3,    KC_BTN2,    KC_WH_U,    _______,
    RGB_TOG,    KC_ACL1,    XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_WH_D,
    RGB_MOD,    KC_ACL2,    XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   XXXXXXXX,   XXXXXXXX,    ______,
                        ________,   ________,   ________,   XXXXXXXX,   ________,   ________,   ________

  ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    enum layer_number layer = 0;
    switch(keycode) {
        case LOWER:
            layer = _LOWER;
            break;
        case HIGHER:
            layer = _HIGHER;
            break;
        default:
            return true;
    }

    if (record->event.pressed) {
        layer_on(layer);
    }else{
        layer_off(layer);
    }

    update_tri_layer(_LOWER, _HIGHER, _ADJUST);

    return false;
}
