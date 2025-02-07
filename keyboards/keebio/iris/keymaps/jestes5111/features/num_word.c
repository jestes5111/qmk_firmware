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

#include "num_word.h"

static bool _num_word_enabled = false;

bool num_word_enabled(void) {
    return _num_word_enabled;
}

void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(_NUM);
}

void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUM);
}

bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) {
        return true;
    }

    switch (keycode) {
        case KC_NO:
        case KC_1 ... KC_0:
        case KC_QUES:
        case KC_LABK:
        case KC_RABK:
        case KC_AT:
        case KC_CIRC:
        case KC_EXLM:
        case KC_MINS:
        case KC_PLUS:
        case KC_EQL:
        case KC_HASH:
        case KC_UNDS:
        case KC_SLSH:
        case KC_ASTR:
        case KC_BSLS:
        case KC_PERC:
        case KC_DOT:
        case KC_COMM:
        case KC_TAB:
        case KC_BSPC:
        case KC_ENT:
        case KC_DEL:
            return true;
        case NW_OFF:
            if (record->event.pressed) {
                disable_num_word();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
            return true;
    }
}
