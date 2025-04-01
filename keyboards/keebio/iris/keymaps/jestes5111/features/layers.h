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

enum layers {
    _RSTHD = 0,
    _GAME,
    _NUM,
    _NAV,
    _APP,
    _SYM,
    _SYS,
    _CODE,
    _EXTRA,
};

// RSTHD layer-taps
#define BSPC_NAV LT(_NAV, KC_BSPC)
#define ENT_APP LT(_APP, KC_ENT)
#define SPC_SYM LT(_SYM, KC_SPC)
#define E_SYM LT(_SYM, KC_E)
#define TAB_SYS LT(_SYS, KC_TAB)
#define DEL_CODE LT(_CODE, KC_DEL)

// Gaming layer-taps
#define ENT_EXT LT(_EXTRA, KC_ENT)

// Short-hand names
#define TYPING DF(_RSTHD)
#define GAMING DF(_GAME)
