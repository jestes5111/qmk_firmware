# Copyright 2023 Jesse Estes (@jestes5111)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

SRC += features/layer_lock.c
SRC += features/layers.c
SRC += features/num_word.c

# Allow macros to be stored outside of `keymap.c`
INTROSPECTION_KEYMAP_C = features/macros.c

CAPS_WORD_ENABLE = yes
NKRO_ENABLE = yes
UNICODEMAP_ENABLE = yes

# Saving space
BACKLIGHT_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
REPEAT_KEY_ENABLE = no
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
TAP_DANCE_ENABLE = no
