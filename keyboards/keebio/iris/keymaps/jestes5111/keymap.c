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

// TODO: try to implement smart case
//    - combo? (i.e., ctrl + cw_togg = snake_case)
// TODO: super alt tab / other way of switching apps/windows

// Home-row mods
#define A_GUI LGUI_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_CTL LCTL_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_CTL RCTL_T(KC_K)
#define L_ALT LALT_T(KC_L) // RALT (AltGr) causes issues with Unicode
#define SCLN_GUI RGUI_T(KC_SCLN)

// Layer taps
#define ESC_LOWR LT(_LOWER, KC_ESC)
#define SPC_MOUSE LT(_MOUSE, KC_SPC)
#define BSPC_UPPR LT(_RAISE, KC_BSPC)
#define ENT_NUM LT(_NUM, KC_ENT)
#define HOME_PASTA LT(_PASTA, KC_HOME)
#define END_FUNC LT(_FUNC, KC_END)

enum layers {
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _MOUSE,
    _NUM,
    _PASTA,
    _FUNC,
};

enum unicode_names {
    DSGS,
    THMB_U,
    THMB_D,
    MOYAI,
};

const uint32_t unicode_map[] PROGMEM = {
    [DSGS] = 0x1F978, // 🥸
    [THMB_U] = 0x1F44D, // 👍
    [THMB_D] = 0x1F44E, // 👎
    [MOYAI] = 0x1F5FF, // 🗿
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_EQL,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_APP,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_MINS,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_GRV,    A_GUI,     S_ALT,     D_CTL,     F_SFT,     KC_G,                                     KC_H,      J_SFT,     K_CTL,     L_ALT,     SCLN_GUI,  KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CW_TOGG,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      HOME_PASTA,         END_FUNC,  KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   CW_TOGG,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    ESC_LOWR,  SPC_MOUSE,                     ENT_NUM,   BSPC_UPPR, KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_GAME] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_0,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,     TO(_QWERTY),
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                     KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_RCTL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_LALT,            KC_RALT,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_LGUI,   ESC_LOWR,  KC_SPC,                        KC_ENT,    BSPC_UPPR, KC_RGUI
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_LOWER] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_VOLU,   KC_VOLD,   KC_MUTE,                                  KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    G(KC_LEFT),G(KC_DOWN),G(KC_UP), G(KC_RGHT), KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     LCAG(KC_1),LCAG(KC_2),LCAG(KC_3),LCAG(KC_4),KC_WHOM,   KC_NO,              KC_LCTL,   S(KC_LEFT),S(KC_DOWN),S(KC_UP), S(KC_RGHT), KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_TRNS,   KC_NO,                         KC_ENT,    KC_BSPC,   KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_RAISE] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LABK,                                  KC_RABK,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_DLR,    KC_AT,     KC_NO,     KC_LPRN,                                  KC_RPRN,   KC_AMPR,   KC_EXLM,   KC_CIRC,   KC_PERC,   KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_NO,     KC_DOT,    KC_HASH,   KC_NO,     KC_LBRC,                                  KC_RBRC,   KC_PIPE,   KC_EQL,    KC_PLUS,   KC_MINS,   KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_CAPS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LCBR,   KC_NO,              KC_NO,     KC_RCBR,   KC_NO,     KC_QUES,   KC_ASTR,   KC_SLSH,   KC_CAPS,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    KC_UNDS,   KC_SPC,                        KC_NO,     KC_TRNS,   KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_MOUSE] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        TO(_GAME), KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        QK_BOOT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_WH_L,   KC_WH_D,   KC_WH_U,   KC_WH_R,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        QK_MAKE,   KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,                                    KC_MS_L,   KC_MS_D,   KC_MS_U,   KC_MS_R,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_BTN3,   KC_BTN4,   KC_BTN5,   KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_NO,     KC_TRNS,                       KC_BTN1,   KC_BTN2,   KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_NUM] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_ESC,    KC_SLSH,   KC_CIRC,   KC_PERC,   KC_DLR,    KC_LABK,                                  KC_RABK,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     TO(_GAME),
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TAB,    KC_ASTR,   KC_7,      KC_8,      KC_9,      KC_LPRN,                                  KC_RPRN,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_BOOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_F2,     KC_MINS,   KC_4,      KC_5,      KC_6,      KC_LBRC,                                  KC_RBRC,   KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,   QK_MAKE,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NUM,    KC_PLUS,   KC_1,      KC_2,      KC_3,      KC_LCBR,   KC_DOT,             KC_NO,     KC_RCBR,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_0,      KC_EQL,    KC_ENT,                        KC_TRNS,   KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_PASTA] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    X(DSGS),   X(THMB_U), KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     X(THMB_D), KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,            KC_NO,     KC_NO,     X(MOYAI),  KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_NO,     KC_NO,                         KC_SPC,    KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_FUNC] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_F10,    KC_F11,    KC_F12,    KC_NO,                                    KC_NO,     KC_F22,    KC_F23,    KC_F24,    KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_NO,                                    KC_NO,     KC_F19,    KC_F20,    KC_F21,    KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_F4,     KC_F5,     KC_F6,     KC_NO,                                    KC_NO,     KC_F16,    KC_F17,    KC_F18,    KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_NO,     KC_NO,              KC_TRNS,   KC_NO,     KC_F13,    KC_F14,    KC_F15,    KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_ESC,    KC_SPC,                        KC_NO,     KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_OFF);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_LOWR:
            return TAPPING_TERM - 25;
        case SPC_MOUSE:
            return TAPPING_TERM - 25;
        case ENT_NUM:
            return TAPPING_TERM - 25;
        case BSPC_UPPR:
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _GAME:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _PASTA:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _FUNC:
            rgblight_sethsv_noeeprom(HSV_CHARTREUSE);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_OFF);
            break;
    }
    return state;
}
