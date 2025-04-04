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

#pragma once

#define EE_HANDS
#define RGBLIGHT_SPLIT
#define RGBLIGHT_SLEEP
#define ENABLE_COMPILE_KEYCODE

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

#define HOME_ROW_MOD_TAPPING_TERM 300
#define HOME_ROW_SHIFT_TAPPING_TERM 200
#define TAPPING_TERM 185
#define GAMING_TAPPING_TERM 100
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define ONESHOT_TIMEOUT 400
#define LAYER_LOCK_IDLE_TIMEOUT 30000

#define SWAP_HANDS_ENABLE

// Saving space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
