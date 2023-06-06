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

// Home-row mods
#define R_GUI LGUI_T(KC_R)
#define S_ALT LALT_T(KC_S)
#define T_CTL LCTL_T(KC_T)
#define H_SFT LSFT_T(KC_H)
#define N_SFT RSFT_T(KC_N)
#define A_CTL RCTL_T(KC_A)
#define I_ALT LALT_T(KC_I) // RALT (AltGr) causes issues with Unicode
#define O_GUI RGUI_T(KC_O)

// Layer taps
#define BSPC_NAV LT(_NAV, KC_BSPC)
#define ENT_SYM LT(_SYM, KC_ENT)
#define HOME_UNI LT(_UNI, KC_HOME)
#define END_SYS LT(_SYS, KC_END)

enum layers {
    _RSTHD,
    _NAV,
    _SYM,
    _UNI,
    _SYS,
    _GAME1,
    _GAME2,
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    CHAR_TAB,
    CHAR_NL,
    DOCSTRING,
    TODO,
};

enum unicode_names {
    I_CIRC,
    DSGS,
    THMB_U,
    THMB_D,
    MOYAI,
    GOAT,
};

const uint32_t unicode_map[] PROGMEM = {
    [I_CIRC] = 0x00EE, // î
    [DSGS] = 0x1F978, // 🥸
    [THMB_U] = 0x1F44D, // 👍
    [THMB_D] = 0x1F44E, // 👎
    [MOYAI] = 0x1F5FF, // 🗿
    [GOAT] = 0x1F98C, // 🦌
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_RSTHD] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_GRV,    KC_7,      KC_8,      KC_9,      KC_0,      KC_5,                                     KC_6,      KC_1,      KC_2,      KC_3,      KC_4,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_J,      KC_C,      KC_Y,      KC_F,      KC_K,                                     KC_Z,      KC_L,      KC_COMM,   KC_U,      KC_Q,      KC_EQL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_UNDS,   R_GUI,     S_ALT,     T_CTL,     H_SFT,     KC_D,                                     KC_M,      N_SFT,     A_CTL,     I_ALT,     O_GUI,     KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CW_TOGG,   KC_SLSH,   KC_V,      KC_G,      KC_P,      KC_B,      HOME_UNI,           END_SYS,   KC_X,      KC_W,      KC_DOT,    KC_SCLN,   KC_MINS,   CW_TOGG,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_DEL,    BSPC_NAV,  KC_SPC,                        KC_E,      ENT_SYM,   KC_TAB
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_NAV] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_VOLD,   KC_VOLU,   KC_MUTE,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R), MEH(KC_T),                                G(KC_LEFT),G(KC_DOWN),G(KC_UP),  G(KC_RGHT),KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        ALT_TAB,   MEH(KC_A), MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G),                                KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_CAPS,   LCAG(KC_1),LCAG(KC_2),LCAG(KC_3),LCAG(KC_4),KC_WHOM,   KC_NO,              KC_LCTL,   S(KC_LEFT),S(KC_DOWN),S(KC_UP),  S(KC_RGHT),KC_NO,     KC_CAPS,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_TRNS,   KC_NO,                         KC_NO,     KC_ENT,    KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_SYM] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_7,      KC_8,      KC_9,      KC_0,      KC_5,                                     KC_6,      KC_1,      KC_2,      KC_3,      KC_4,      KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_DOT,                                   KC_AMPR,   KC_SCLN,   KC_LBRC,   KC_RBRC,   KC_PERC,   CHAR_TAB,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_UNDS,   KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,                                  KC_PIPE,   KC_COLN,   KC_LPRN,   KC_RPRN,   KC_QUES,   CHAR_NL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        TODO,      KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_GRV,    DOCSTRING,          KC_NO,     KC_TILD,   KC_DLR,    KC_LCBR,   KC_RCBR,   KC_AT,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_DEL,    KC_BSPC,   KC_SPC,                        KC_NO,     KC_TRNS,   KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_UNI] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    X(DSGS),   X(THMB_U), X(I_CIRC), KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     X(GOAT),                                  KC_NO,     X(THMB_D), KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,            KC_NO,     KC_NO,     X(MOYAI),  KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_NO,     KC_NO,                         KC_ENT,    KC_BSPC,   KC_TAB
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),


    [_SYS] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_F12,    KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F5,                                    KC_F6,     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F11,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_BOOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     LSG(KC_S), KC_NO,     KC_NO,     KC_NO,                                    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_MAKE,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,    TO(_RSTHD),TO(_GAME1),
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_NO,     KC_NO,                         KC_NO,     KC_NO,     KC_NO
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
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_LALT,            KC_LALT,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_LSFT,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                             MO(_GAME2), SH_MON,    KC_SPC,                        KC_NO,     KC_TRNS,   KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_GAME2] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_VOLU,   KC_VOLD,   KC_MUTE,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    TO(_RSTHD),
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_ESC,    KC_F13,    KC_F14,    KC_F15,    KC_F16,    KC_TILD,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_F17,    KC_F18,    KC_F19,    KC_F20,    KC_EXLM,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LSFT,   KC_F21,    KC_F22,    KC_F23,    KC_F24,    KC_AT,     KC_NO,              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TRNS,   KC_NO,     KC_NO,                         KC_NO,     KC_NO,     KC_NO
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_OFF);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case CHAR_TAB:
                SEND_STRING("\\t");
                return false;
            case CHAR_NL:
                SEND_STRING("\\n");
                return false;
            case DOCSTRING:
                SEND_STRING("\"\"\"\"\"\"");
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                return false;
            case TODO:
                SEND_STRING(SS_LCTL("/") "TODO: ");
                return false;
        }
    }

    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
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
            return true;
        default:
            return false;
    }
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 250) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_NAV:
        case ENT_SYM:
            return TAPPING_TERM - 15;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _UNI:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _SYS:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _GAME1:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _GAME2:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_OFF);
            break;
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
