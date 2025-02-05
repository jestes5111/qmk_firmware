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

#include QMK_KEYBOARD_H

#include "layers.h"
#include "macros.h"
#include "unicode.h"

const uint16_t PROGMEM a_grave[] = {KC_GRV, A_CTL, COMBO_END};
const uint16_t PROGMEM e_grave[] = {KC_GRV, E_SYM, COMBO_END};
const uint16_t PROGMEM i_grave[] = {KC_GRV, I_ALT, COMBO_END};
const uint16_t PROGMEM o_grave[] = {KC_GRV, O_GUI, COMBO_END};
const uint16_t PROGMEM u_grave[] = {KC_GRV, KC_U, COMBO_END};

combo_t key_combos[] = {
    COMBO(a_grave, A_GRAVE),
    COMBO(e_grave, E_GRAVE),
    COMBO(i_grave, I_GRAVE),
    COMBO(o_grave, O_GRAVE),
    COMBO(u_grave, U_GRAVE),
};
