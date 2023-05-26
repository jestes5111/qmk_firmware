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
#define A_GUI LGUI_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_CTL LCTL_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_CTL RCTL_T(KC_K)
#define L_ALT LALT_T(KC_L) // RALT (AltGr) causes issues with Unicode
#define SCLN_GUI RGUI_T(KC_SCLN)

// Layer taps
#define ESC_NAV LT(_NAV, KC_ESC)
#define SPC_MOUSE LT(_MOUSE, KC_SPC)
#define BSPC_SYM LT(_SYM, KC_BSPC)
#define ENT_NUM LT(_NUM, KC_ENT)
#define HOME_UNI LT(_UNI, KC_HOME)

// Home-row mods (RSTHD)
#define R_GUI LGUI_T(KC_R)
#define S_ALT LALT_T(KC_S)
#define T_CTL LCTL_T(KC_T)
#define H_SFT LSFT_T(KC_H)
#define N_SFT RSFT_T(KC_N)
#define A_CTL RCTL_T(KC_A)
#define I_ALT LALT_T(KC_I) // RALT (AltGr) causes issues with Unicode
#define O_GUI RGUI_T(KC_O)

// Layer taps (RSTHD)
#define BSPC_NAV LT(_NAV, KC_BSPC)
#define SPC_NUM LT(_NUM, KC_SPC)
#define ENT_SYM LT(_SYM, KC_ENT)

enum layers {
    _QWERTY,
    _RSTHD,
    _GAME,
    _NAV,
    _SYM,
    _MOUSE,
    _NUM,
    _UNI,
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

const key_override_t **key_overrides = (const key_override_t *[]) {
	&ko_make_basic(MOD_MASK_SHIFT, HOME_UNI, KC_PGUP),
	&ko_make_basic(MOD_MASK_SHIFT, KC_END, KC_PGDN),
	NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_EQL,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_GRV,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_MINS,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_UNDS,   A_GUI,     S_ALT,     D_CTL,     F_SFT,     KC_G,                                     KC_H,      J_SFT,     K_CTL,     L_ALT,     SCLN_GUI,  KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CW_TOGG,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      HOME_UNI,           KC_END,    KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   CW_TOGG,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    ESC_NAV,   SPC_MOUSE,                     ENT_NUM,   BSPC_SYM,  KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_RSTHD] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_GRV,    KC_7,      KC_8,      KC_9,      KC_0,      KC_5,                                     KC_6,      KC_1,      KC_2,      KC_3,      KC_4,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TAB,    KC_J,      KC_C,      KC_Y,      KC_F,      KC_K,                                     KC_Z,      KC_L,      KC_COMM,   KC_U,      KC_Q,      KC_EQL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_UNDS,   R_GUI,     S_ALT,     T_CTL,     H_SFT,     KC_D,                                     KC_M,      N_SFT,     A_CTL,     I_ALT,     O_GUI,     KC_QUOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CW_TOGG,   KC_SLSH,   KC_V,      KC_G,      KC_P,      KC_B,      HOME_UNI,           KC_END,    KC_X,      KC_W,      KC_DOT,    KC_SCLN,   KC_MINS,   CW_TOGG,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_ESC,    BSPC_NAV,  KC_E,                          SPC_NUM,   ENT_SYM,   KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_GAME] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_0,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,     TO(_QWERTY),
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_GRV,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                     KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_RCTL,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_LALT,            KC_RALT,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    ESC_NAV,   KC_SPC,                        KC_ENT,    BSPC_SYM,  KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_NAV] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_MPLY,   KC_MPRV,   KC_MNXT,   KC_VOLU,   KC_VOLD,   KC_MUTE,                                  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     MEH(KC_Q), MEH(KC_W), MEH(KC_E), MEH(KC_R), MEH(KC_T),                                G(KC_LEFT),G(KC_DOWN),G(KC_UP),  G(KC_RGHT),KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        ALT_TAB,   MEH(KC_A), MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G),                                KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,     KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     LCAG(KC_1),LCAG(KC_2),LCAG(KC_3),LCAG(KC_4),KC_WHOM,   KC_NO,              KC_LCTL,   S(KC_LEFT),S(KC_DOWN),S(KC_UP),  S(KC_RGHT),KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_NO,     KC_TRNS,   KC_NO,                         KC_ENT,    KC_BSPC,   KC_DEL
    //                                       └──────────┴──────────┴──────────┘                   └──────────┴──────────┴──────────┘
    ),

    [_SYM] = LAYOUT(
    // ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                              ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_F12,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CHAR_TAB,  KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_DOT,                                   KC_AMPR,   KC_SCLN,   KC_LBRC,   KC_RBRC,   KC_PERC,   KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        CHAR_NL,   KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,                                  KC_PIPE,   KC_COLN,   KC_LPRN,   KC_RPRN,   KC_QUES,   KC_NO,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        TODO,      KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_GRV,    DOCSTRING,          KC_NO,     KC_TILD,   KC_DLR,    KC_LCBR,   KC_RCBR,   KC_AT,     KC_NO,
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
        KC_NO,     KC_SLSH,   KC_CIRC,   KC_PERC,   KC_DLR,    TO(_NUM),                                TO(_QWERTY),TO(_RSTHD),KC_NO,     KC_NO,     KC_NO,     TO(_GAME),
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_ASTR,   KC_7,      KC_8,      KC_9,      KC_EXLM,                                  KC_NO,     KC_NO,     KC_LBRC,   KC_RBRC,   KC_NO,     QK_BOOT,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_MINS,   KC_4,      KC_5,      KC_6,      KC_0,                                     KC_NO,     KC_F2,     KC_LPRN,   KC_RPRN,   KC_NO,     QK_MAKE,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐        ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO,     KC_PLUS,   KC_1,      KC_2,      KC_3,      KC_DOT,    KC_EQL,             KC_NO,     KC_NO,     KC_NO,     KC_LABK,   KC_RABK,   KC_NO,     KC_NO,
    // └──────────┴──────────┴──────────┴────┬─────┴────┬─────┴────┬─────┴────┬─────┘        └────┬─────┴────┬─────┴────┬─────┴────┬─────┴──────────┴──────────┴──────────┘
                                              KC_TAB,    KC_ESC,    KC_ENT,                        KC_TRNS,   KC_BSPC,   KC_NO
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
        case SPC_MOUSE:
        case ENT_NUM:
            return TAPPING_TERM - 25;
        case ESC_NAV:
        case BSPC_SYM:
            return TAPPING_TERM - 45;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RSTHD:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _GAME:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _UNI:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_OFF);
            break;
    }
    return state;
}
