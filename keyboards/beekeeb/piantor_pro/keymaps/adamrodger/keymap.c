/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2024 Adam Rodger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// use UK ISO layout instead of US ANSI
#include <keymap_uk.h>

// home row mods
#define M_GUI_A GUI_T(KC_A)
#define M_GUI_C GUI_T(KC_C)
#define M_GUI_SCL GUI_T(KC_SCLN)

#define M_ALT_S ALT_T(KC_S)
#define M_ALT_L ALT_T(KC_L)
#define M_ALT_R ALT_T(KC_R)
#define M_ALT_I ALT_T(KC_I)

#define M_CTL_D CTL_T(KC_D)
#define M_CTL_K CTL_T(KC_K)
#define M_CTL_S CTL_T(KC_S)
#define M_CTL_E CTL_T(KC_E)

#define M_SFT_F SFT_T(KC_F)
#define M_SFT_J SFT_T(KC_J)
#define M_SFT_T SFT_T(KC_T)
#define M_SFT_N SFT_T(KC_N)

// Macros
enum custom_keycodes {
    VIM_WQ = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_WQ:
            if (record->event.pressed) {
                // Sends ESC, then :wq, then Enter to exit Vim
                SEND_STRING(SS_TAP(X_ESC) ":wq" SS_TAP(X_ENTER));
            }
            return false;
    }
    return true;
}
// End Macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                         KC_Z,    KC_F,    KC_O,    KC_U, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, M_GUI_C, M_ALT_R, M_CTL_S, M_SFT_T,    KC_G,                         KC_M, M_SFT_N, M_CTL_E, M_ALT_I, M_GUI_A, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                         KC_X,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  VIM_WQ,                      KC_LPRN,    KC_7,    KC_8,    KC_9, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_WBAK, KC_WFWD, MS_WHLU,                      KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), MS_WHLD,                      KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(3),    KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   UK_AT, KC_LABK, KC_RABK, KC_UNDS,  UK_PND,                      KC_COLN, KC_LCBR, KC_RCBR, UK_BSLS,  KC_GRV, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_MINS, KC_PPLS,  KC_EQL,  UK_DLR,                      KC_AMPR, KC_LPRN, KC_RPRN, UK_DQUO, UK_TILD, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UK_HASH, KC_SLSH, KC_PAST, KC_PERC, UK_EURO,                      UK_PIPE, KC_LBRC, KC_RBRC, KC_CIRC, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(3), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       KC_INS, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DF(4), KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                       KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
