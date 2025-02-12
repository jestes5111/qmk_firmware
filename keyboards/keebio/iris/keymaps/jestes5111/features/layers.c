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

#include QMK_KEYBOARD_H

#include "layers.h"
#include "socd_cleaner.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _APP:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _SYS:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _CODE:
            rgblight_sethsv_noeeprom(HSV_CORAL);
            break;
        case _EXTRA:
            rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        default:
            switch (get_highest_layer(default_layer_state)) {
                case _RSTHD:
                    rgblight_sethsv_noeeprom(HSV_OFF);
                    keymap_config.nkro = false;
                    socd_cleaner_enabled = false;
                    break;
                case _GAME:
                    rgblight_sethsv_noeeprom(HSV_BLUE);
                    keymap_config.nkro = true;
                    socd_cleaner_enabled = true;
                    break;
            }
    }
    return state;
}
