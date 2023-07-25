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

#pragma once

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
#define ENT_APP LT(_APP, KC_ENT)
#define SPC_SYM LT(_SYM, KC_SPC)
#define E_SYM LT(_SYM, KC_E)
#define TAB_SYS LT(_SYS, KC_TAB)
#define DEL_UNI LT(_UNI, KC_DEL)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

// Windows shortcuts
#define APP_1 G(KC_1)
#define APP_2 G(KC_2)
#define APP_3 G(KC_3)
#define APP_4 G(KC_4)
#define APP_5 G(KC_5)
#define NEW_APP_1 LSG(KC_1)
#define NEW_APP_2 LSG(KC_2)
#define NEW_APP_3 LSG(KC_3)
#define NEW_APP_4 LSG(KC_4)
#define NEW_APP_5 LSG(KC_5)
#define LAUNCH_1 MEH(KC_1)
#define LAUNCH_2 MEH(KC_2)
#define LAUNCH_3 MEH(KC_3)
#define LAUNCH_4 MEH(KC_4)
#define LAUNCH_5 MEH(KC_5)
#define FZ_1 LCAG(KC_1)
#define FZ_2 LCAG(KC_2)
#define FZ_3 LCAG(KC_3)
#define FZ_4 LCAG(KC_4)
#define WINDOW_L G(KC_LEFT)
#define WINDOW_D G(KC_DOWN)
#define WINDOW_U G(KC_UP)
#define WINDOW_R G(KC_RGHT)
#define MUTE_MIC RCS(KC_M)
#define DEAFEN RCS(KC_D)
#define TASK_MGR RCS(KC_ESC)
#define SNIP_TOOL LSG(KC_S)
#define DR_TOGG LSA(KC_D)
#define BW_FILL RCS(KC_L)
#define NEXT_TAB C(KC_PGDN)
#define PREV_TAB C(KC_PGUP)
#define QUIT_APP A(KC_F4)
#define SEL_ALL C(KC_A)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)

// More complex macros
enum custom_keycodes {
    LYR_LOCK = SAFE_RANGE,
    UP_DIR,
    DOCSTRING,
    TODO,
};

bool process_macros(uint16_t keycode, keyrecord_t *record);
