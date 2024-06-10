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
#include "num_word.h"

// Key overrides
const key_override_t paste_as_plain_text_override = ko_make_basic(MOD_MASK_SHIFT, PASTE, PASTE_PT);
const key_override_t **key_overrides = (const key_override_t *[]) {
    &paste_as_plain_text_override,
    NULL
};

bool process_macros(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case UP_DIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case DOCSTRING:
            if (record->event.pressed) {
                SEND_STRING("\"\"\"");
            }
            return false;
        case TODO:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_SLSH);
                unregister_code(KC_LCTL);
                SEND_STRING("TODO: ");
            }
            return false;
        case NW_ON:
            if (record->event.pressed) {
                enable_num_word();
            }
            return false;
    }
    return true;
}
