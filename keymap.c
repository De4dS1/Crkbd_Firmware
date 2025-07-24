/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Spanish keys
#include "keymap_spanish.h"

// Caps word
//#include "capsword.h"

// Key overrides
const key_override_t delete_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &delete_ko
};

// Tap dances
#include "tapdance.h"

enum{
    SFTC,
    ACCW,
    COMM,
    DOT,
    MINS,
// Layers
    LYR1,
    LYR2,
// Symbols
    AT,
    PLUS,
    CIRC,
    QUES,
    EXCL,
    BRCK,
    PRNT,
    BRCS,
    QUOT,
    PIPE,
// Gaming
    TAB,
    AUXT,
    AUXG,
    AUXB,
    AUX1,
    AUX2,
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [SFTC] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [ACCW] = ACTION_TAP_DANCE_FN(Accw), // ES_QUOT -> Caps Word
    [COMM] = ACTION_TAP_DANCE_DOUBLE(ES_COMM, ES_SCLN), // , -> ;
    [DOT]  = ACTION_TAP_DANCE_DOUBLE(ES_DOT, ES_COLN), // . -> :
    [MINS] = ACTION_TAP_DANCE_DOUBLE(ES_MINS, ES_UNDS), // - -> _
    [AT]   = ACTION_TAP_DANCE_DOUBLE(ES_AT, ES_TILD), // @ -> ~
    [PLUS] = ACTION_TAP_DANCE_DOUBLE(ES_PLUS, ES_ASTR), // + -> *
    [CIRC] = ACTION_TAP_DANCE_DOUBLE(ES_CIRC, ES_DIAE), // ^ -> "
    [QUES] = ACTION_TAP_DANCE_DOUBLE(ES_IQUE, ES_QUES), // ¿ -> ?
    [EXCL] = ACTION_TAP_DANCE_DOUBLE(ES_IEXL, ES_EXLM), // ¡ -> !
    [BRCK] = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC), // [ -> ]
    [PRNT] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN), // ( -> )
    [BRCS] = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR), // { -> }
    [QUOT] = ACTION_TAP_DANCE_DOUBLE(ES_DQUO, ES_QUOT), // " -> '
    [PIPE] = ACTION_TAP_DANCE_DOUBLE(ES_HASH, ES_PIPE), // # -> |

    [LYR1] = ACTION_TAP_DANCE_FN(SymGm),
    [LYR2] = ACTION_TAP_DANCE_FN(FnTex),

    [TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_Y), // Tab -> Y
    [AUXT] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_T), // R -> T
    [AUXG] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_G), // F -> G
    [AUXB] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_B), // V -> B
    [AUX1] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_5), // 3 -> 4
    [AUX2] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_7), // 5 -> 6
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case TD(TAB):
        case TD(AUXT):
        case TD(AUXG):
        case TD(AUXB):
        case TD(AUX1):
        case TD(AUX2):
            return 120;
        default:
            return TAPPING_TERM;
    }
}


// Layers
enum {
    Wrtng,
    Sym,
    Fn,
    Gaming,
    Latex,
    Conf,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Wrtng] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(SFTC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,   KC_J,    KC_K,    KC_L, ES_NTIL, TD(ACCW),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,   KC_M, TD(COMM), TD(DOT), TD(MINS), KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TD(LYR1),  KC_SPC,     KC_ENT, TD(LYR2), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

    [Sym] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, ES_SLSH, TD(AT), TD(PIPE), ES_DLR, ES_PERC,                      TD(QUES), KC_7,    KC_8,    KC_9,   TD(EXCL), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  TD(PLUS),                     TD(BRCK), KC_4,    KC_5,    KC_6,   TD(PRNT), KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, ES_BSLS, ES_EQL, ES_AMPR, TD(CIRC), ES_LABK,                     TD(BRCS), KC_1,    KC_2,    KC_3,   TD(QUOT), KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,   KC_0,   KC_LGUI, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [Fn] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,                      KC_TRNS, KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BRIU,                      KC_TRNS, KC_F4,   KC_F5,    KC_F6,  KC_F11,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRID,                      KC_TRNS, KC_F1,   KC_F2,    KC_F3,  KC_F12,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, TG(Conf), KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [Gaming] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TD(TAB),   KC_1,   KC_Q,    KC_W,   KC_E,   TD(AUXT),                    KC_TRNS,  KC_F7,   KC_F8,    KC_F9, KC_F10,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_2,   KC_A,    KC_S,   KC_D,   TD(AUXG),                    KC_TRNS,  KC_F4,   KC_F5,    KC_F6, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_3,   KC_Z,    KC_X,   KC_C,   TD(AUXB),                    KC_TRNS,  KC_F1,   KC_F2,    KC_F3, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        TD(AUX1), TD(AUX2), KC_SPC,    KC_TRNS, TG(Gaming), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
    [Conf] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, TG(Conf), KC_SPC,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
    [Latex] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, TG(Latex), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )

};

#include "capsword.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case TD(LYR1):
            if (record->event.pressed) layer_on(Sym);
            else layer_off(Sym);
            return true;
        case TD(LYR2):
            if (record->event.pressed) layer_on(Fn);
            else layer_off(Fn);
            return true;
        default: return true;
    }
}

#include "oled.h"
bool oled_task_user(void){
     if (!is_keyboard_master()) render_logo();

     if (is_keyboard_master()){
	Write_lyr();

	}
     return false;
}

