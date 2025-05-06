/**
 * Copyright 2025 Jesse Estes (@jestes5111)
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

static uint16_t num_word_timer = 0;
// static uint16_t spc_sym_timer = 0;
static bool is_num_word_on = false;

bool is_num_word_enabled(void) {
    return is_num_word_on;
}

void enable_num_word(void) {
    if (is_num_word_on) return;
    is_num_word_on = true;
    layer_on(_NUM);
}

void disable_num_word(void) {
    if (!is_num_word_on) return;
    is_num_word_on = false;
    layer_off(_NUM);
}

void toggle_num_word(void) {
    if (is_num_word_on) {
        disable_num_word();
    } else {
        enable_num_word();
    }
}

bool should_terminate_num_word(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_NO:
        case KC_1 ... KC_0:
        case KC_LABK:
        case KC_RABK:
        case KC_AT:
        case KC_CIRC:
        case KC_BSPC:
        case KC_EXLM:
        case KC_MINS:
        case KC_PLUS:
        case KC_EQL:
        case KC_HASH:
        case KC_QUES:
        case KC_SLSH:
        case KC_ASTR:
        case KC_BSLS:
        case KC_PERC:
        case KC_COLN:
        case KC_DOT:
        case KC_DEL:
        case KC_COMM:
        case KC_TAB:
        case KC_ENT:
        case E_SYM:
        case KC_TILD:
        case KC_LBRC:
        case KC_RBRC:
        case KC_AMPR:
        case KC_LPRN:
        case KC_RPRN:
        case KC_DQUO:
        case KC_DLR:
        case KC_LCBR:
        case KC_RCBR:
        case KC_QUOT:
        case TAB_NAV:
        case KC_LEFT:
        case KC_DOWN:
        case KC_UP:
        case KC_RGHT:
            return false;

        case SPC_SYM:
            if (record->event.pressed && record->tap.count != 0) {
                return true;
            }
            return false;

        default:
            if (record->event.pressed && layer_state_is(_SYM)) {
                return true;
            }
            return false;
    }

    // Should be unreachable
    return false;
}


bool process_num_word(uint16_t keycode, keyrecord_t *record) {
    if (keycode == NW_ON) {
        if (record->event.pressed) {
            enable_num_word();
            num_word_timer = timer_read();
            return false;
        } else {
            if (timer_elapsed(num_word_timer) > TAPPING_TERM) {
                // If the user held the key longer than TAPPING_TERM,
                // consider it a hold, and disable the behavior on key release.
                disable_num_word();
                return false;
            }
        }
    }

    // Other than the custom keycodes and space, nothing else in this feature
    // will activate if the behavior is not on, so allow QMK to handle the
    // event as usual
    if (!is_num_word_on) {
        return true;
    }

    // Nothing else acts on key release, either
    if (!record->event.pressed) {
        return true;
    }

    if (should_terminate_num_word(keycode, record)) {
        disable_num_word();
    }

    return true;
}
