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

enum unicode_names {
    // General purpose
    _EN_DASH,
    _EM_DASH,
    _I_CIRCUMFLEX_LOWER,
    _I_CIRCUMFLEX_UPPER,

    // Scottish Gaelic
    _A_GRAVE_LOWER,
    _A_GRAVE_UPPER,
    _E_GRAVE_LOWER,
    _E_GRAVE_UPPER,
    _I_GRAVE_LOWER,
    _I_GRAVE_UPPER,
    _O_GRAVE_LOWER,
    _O_GRAVE_UPPER,
    _U_GRAVE_LOWER,
    _U_GRAVE_UPPER,
};

const uint32_t unicode_map[] PROGMEM = {
    // General purpose
    [_EN_DASH] = 0x2013, // –
    [_EM_DASH] = 0x2014, // —
    [_I_CIRCUMFLEX_LOWER] = 0x00EE, // î
    [_I_CIRCUMFLEX_UPPER] = 0x00CE, // Î

    // Scottish Gaelic
    [_A_GRAVE_LOWER] = 0x00E0, // à
    [_A_GRAVE_UPPER] = 0x00C0, // À
    [_E_GRAVE_LOWER] = 0x00E8, // è
    [_E_GRAVE_UPPER] = 0x00C8, // È
    [_I_GRAVE_LOWER] = 0x00EC, // ì
    [_I_GRAVE_UPPER] = 0x00CC, // Ì
    [_O_GRAVE_LOWER] = 0x00F2, // ò
    [_O_GRAVE_UPPER] = 0x00D2, // Ò
    [_U_GRAVE_LOWER] = 0x00F9, // ù
    [_U_GRAVE_UPPER] = 0x00D9, // Ù
};

// General purpose
#define DASH XP(_EN_DASH, _EM_DASH)
#define I_CIRC XP(_I_CIRCUMFLEX_LOWER, _I_CIRCUMFLEX_UPPER)

// Scottish Gaelic
#define A_GRAVE XP(_A_GRAVE_LOWER, _A_GRAVE_UPPER)
#define E_GRAVE XP(_E_GRAVE_LOWER, _E_GRAVE_UPPER)
#define I_GRAVE XP(_I_GRAVE_LOWER, _I_GRAVE_UPPER)
#define O_GRAVE XP(_O_GRAVE_LOWER, _O_GRAVE_UPPER)
#define U_GRAVE XP(_U_GRAVE_LOWER, _U_GRAVE_UPPER)
