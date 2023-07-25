/*
Copyright 2023 Jesse Estes (@jestes5111)

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

#include "features/key_overrides.h"
#include "features/layer_lock.h"
#include "features/macros.h"
#include "features/unicode.h"

enum layers {
    _RSTHD,
    _NAV,
    _APP,
    _SYM,
    _UNI,
    _SYS,
    _GAME1,
    _GAME2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_RSTHD] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_GRV,    KC_7,      KC_8,      KC_9,      KC_0,      KC_5,                                     KC_6,      KC_1,      KC_2,      KC_3,      KC_4,      KC_SLSH,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_J,      KC_C,      KC_Y,      KC_F,      KC_K,                                     KC_Z,      KC_L,      KC_COMM,   KC_U,      KC_Q,      DASH,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_UNDS,   R_GUI,     S_ALT,     T_CTL,     H_SFT,     KC_D,                                     KC_M,      N_SFT,     A_CTL,     I_ALT,     O_GUI,     KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CW_TOGG,   OS_LSFT,   KC_V,      KC_G,      KC_P,      KC_B,      QK_REP,             QK_REP,    KC_X,      KC_W,      KC_DOT,    KC_SCLN,   OS_RSFT,   CW_TOGG,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              TAB_SYS,   BSPC_NAV,  SPC_SYM,                       E_SYM,     ENT_APP,   DEL_UNI
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_NAV] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   SEL_ALL,                                  KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              LYR_LOCK,  KC_INS,    PASTE,     COPY,      CUT,       UNDO,      REDO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    KC_TRNS,   KC_NO,                         KC_APP,    KC_ENT,    KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_APP] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        QUIT_APP,  LAUNCH_1,  LAUNCH_2,  LAUNCH_3,  LAUNCH_4,  LAUNCH_5,                                 KC_NO,     MUTE_MIC,  KC_VOLD,   KC_VOLU,   KC_MUTE,   KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     APP_1,     APP_2,     APP_3,     APP_4,     APP_5,                                    KC_NO,     KC_WBAK,   PREV_TAB,  NEXT_TAB,  KC_WFWD,   KC_WREF,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     NEW_APP_1, NEW_APP_2, NEW_APP_3, NEW_APP_4, NEW_APP_5, LYR_LOCK,           KC_NO,     KC_NO,     KC_MPRV,   KC_MSTP,   KC_MPLY,   KC_MNXT,   KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_NO,     KC_NO,                         KC_NO,     KC_TRNS,   KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_SYM] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_7,      KC_8,      KC_9,      KC_0,      KC_5,                                     KC_6,      KC_1,      KC_2,      KC_3,      KC_4,      KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_LABK,   KC_RABK,   KC_AT,     UP_DIR,                                   KC_PIPE,   KC_AMPR,   KC_LBRC,   KC_RBRC,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        TODO,      KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,                                  KC_TILD,   KC_COLN,   KC_LPRN,   KC_RPRN,   KC_QUES,   DOCSTRING,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_GRV,    LYR_LOCK,           LYR_LOCK,  KC_NO,     KC_DLR,    KC_LCBR,   KC_RCBR,   KC_PERC,   KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    KC_BSPC,   KC_TRNS,                       KC_TRNS,   KC_ENT,    KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_UNI] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     FIRE,      KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     THINK_SAL, SKULL,     THUMB,     KC_LSFT,   DISGUISE,                                 MOYAI,     KC_RSFT,   ALIEN,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     GOAT,      KC_NO,     MID_FING,  LYR_LOCK,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_BSPC,   KC_SPC,                        KC_NO,     KC_ENT,    KC_TRNS
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),


    [_SYS] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_F12,    KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F5,                                    KC_F6,     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F11,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        TASK_MGR,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     FZ_1,      FZ_2,      FZ_3,      FZ_4,      KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     SNIP_TOOL, BW_FILL,   DR_TOGG,   KC_NO,                                    KC_NO,     WINDOW_L,  WINDOW_D,  WINDOW_U,  WINDOW_R,  QK_MAKE,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_CAPS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    DF(_GAME1),
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TRNS,   KC_NO,     KC_NO,                         KC_NO,     KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_GAME1] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_TAB,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_F5,     KC_F4,     KC_F3,     KC_F2,     KC_F1,     KC_TAB,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_ESC,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                     KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_LCTL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_LALT,            KC_NO,     KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_LSFT,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                             MO(_GAME2), SH_MON,    KC_SPC,                        KC_NO,     KC_TRNS,   KC_RCTL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_GAME2] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_VOLU,   KC_VOLD,   KC_MUTE,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_F13,    KC_F14,    KC_F15,    KC_F16,    KC_TILD,                                  KC_NO,     MUTE_MIC,  KC_NO,     KC_NO,     DEAFEN,    KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_F17,    KC_F18,    KC_F19,    KC_F20,    KC_HASH,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LSFT,   KC_F21,    KC_F22,    KC_F23,    KC_F24,    KC_GRV,    KC_NO,              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    DF(_RSTHD),
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TRNS,   KC_NO,     KC_NO,                         KC_NO,     KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_OFF);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    keymap_config.nkro = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LYR_LOCK)) return false;
    if (!process_macros(keycode, record)) return false;
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
        case KC_SLSH:
        case KC_BSLS:
        case KC_QUOT:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case R_GUI:
        case S_ALT:
        case T_CTL:
        case H_SFT:
        case N_SFT:
        case A_CTL:
        case I_ALT:
        case O_GUI:
            return HOME_ROW_MOD_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _APP:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _UNI:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _SYS:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _GAME2:
            rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        default:
            switch (get_highest_layer(default_layer_state)) {
                case _RSTHD:
                    rgblight_sethsv_noeeprom(HSV_OFF);
                    keymap_config.nkro = false;
                    break;
                case _GAME1:
                    rgblight_sethsv_noeeprom(HSV_BLUE);
                    keymap_config.nkro = true;
                    break;
            }
    }
    return state;
}

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}},
    {{0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}},
    {{0,9}, {1,9}, {2,9}, {3,9}, {4,9}, {5,9}},
    /* Right hand, matrix positions */
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}},
    {{0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}},
    {{0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}},
    {{0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}},
};
