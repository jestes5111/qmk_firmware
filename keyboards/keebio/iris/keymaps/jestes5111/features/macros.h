/**
 * Copyright 2023 Jesse Estes (@jestes5111)
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

// One-shot shift
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

// Vim shortcuts
#define SFT_G S(KC_G)

// Windows shortcuts
#define TB_1 G(KC_1)
#define TB_2 G(KC_2)
#define TB_3 G(KC_3)
#define TB_4 G(KC_4)
#define TB_5 G(KC_5)
#define SC_1 MEH(KC_1)
#define SC_2 MEH(KC_2)
#define SC_3 MEH(KC_3)
#define SC_4 MEH(KC_4)
#define SC_5 MEH(KC_5)
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
#define CLOSE_TAB C(KC_W)
#define OPEN_TAB C(KC_T)
#define REOPEN_TAB RCS(KC_T)
#define NEXT_TAB C(KC_PGDN)
#define PREV_TAB C(KC_PGUP)
#define QUIT_APP A(KC_F4)
#define SEL_ALL C(KC_A)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define PASTE_PT LCAG(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)

// More complex macros
enum custom_keycodes {
    LYR_LOCK = SAFE_RANGE,
    UP_DIR,
    DOCSTRING,
    TODO,
    NW_ON,
    NW_OFF,
};

bool process_macros(uint16_t keycode, const keyrecord_t *record);
