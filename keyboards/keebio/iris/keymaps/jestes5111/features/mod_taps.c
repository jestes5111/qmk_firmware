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

#define IS_HOMEROW(r) (r->event.key.row == 2 || r->event.key.row == 7)
#define IS_UNILATERAL(r, n) ( \
    (r->event.key.row == 2 && 0 <= n.event.key.row && n.event.key.row <= 4) || \
    (r->event.key.row == 7 && 5 <= n.event.key.row && n.event.key.row <= 9) \
)
#define IS_BILATERAL(r, n) ( \
    (r->event.key.row == 2 && 5 <= n.event.key.row && n.event.key.row <= 9) || \
    (r->event.key.row == 7 && 0 <= n.event.key.row && n.event.key.row <= 4) \
)

static uint16_t inter_keycode;
static keyrecord_t inter_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        inter_keycode = keycode;
        inter_record = *record;
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (IS_UNILATERAL(record, inter_record)) {
        record->tap.count++;
        record->tap.interrupted = false;
        process_record(record);
    }

    return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_BILATERAL(record, inter_record);
}
