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

#include "macros.h"

// Key overrides
const key_override_t paste_as_plain_text_override = ko_make_basic(MOD_MASK_SHIFT, PASTE, PASTE_PT);
const key_override_t question_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);
const key_override_t exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
const key_override_t backslash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
const key_override_t pipe_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);
const key_override_t *key_overrides[] = {
    &paste_as_plain_text_override,
    &question_override,
    &exclamation_override,
    &backslash_override,
    &pipe_override
};

uint8_t mod_state;
bool process_macros(uint16_t keycode, const keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case NW_ON:
            if (record->event.pressed) {
                enable_num_word();
            }
            return false;
        case NW_OFF:
            if (record->event.pressed) {
                disable_num_word();
            }
            return false;
        case UP_DIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case OPEN_TAG:
            if (record->event.pressed) {
                SEND_STRING("<>");
                tap_code(KC_LEFT);
            }
            return false;
        case CLOSE_TAG:
            if (record->event.pressed) {
                SEND_STRING("</>");
                tap_code(KC_LEFT);
            }
            return false;
        case CW_EXT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    if (is_caps_word_on()) {
                        // Prevent odd behavior by ensuring Caps Word is off
                        caps_word_off();
                    }
                    tap_code(KC_CAPS);
                } else {
                    if (host_keyboard_led_state().caps_lock) {
                        // Turn off Caps Lock
                        tap_code(KC_CAPS);
                        // Prevent next word from being capitalized
                        caps_word_toggle();
                    }
                    caps_word_toggle();
                }
            }
            return false;
    }
    return true;
}
