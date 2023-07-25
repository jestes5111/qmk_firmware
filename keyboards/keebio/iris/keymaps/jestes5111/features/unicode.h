/*
Copyright 2023 Jesse Estes (@jestes5111)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

enum unicode_names {
    // Non-emoji
    _EN_DASH,
    _EM_DASH,
    _I_CIRCUMFLEX_LOWER,
    _I_CIRCUMFLEX_UPPER,

    // Emoji
    _ALIEN,
    _DISGUISED_FACE,
    _FIRE,
    _GOAT,
    _MIDDLE_FINGER,
    _MOYAI,
    _SALUTE,
    _SKULL,
    _THINKING,
    _THUMB_UP,
    _THUMB_DOWN,
};

const uint32_t unicode_map[] PROGMEM = {
    // Non-emoji
    [_EN_DASH] = 0x2013, // –
    [_EM_DASH] = 0x2014, // —
    [_I_CIRCUMFLEX_LOWER] = 0x00EE, // î
    [_I_CIRCUMFLEX_UPPER] = 0x00CE, // Î

    // Emoji
    [_ALIEN] = 0x1F47D, // 👽
    [_DISGUISED_FACE] = 0x1F978, // 🥸
    [_FIRE] = 0x1F525, // 🔥
    [_GOAT] = 0x1F98C, // 🦌
    [_MIDDLE_FINGER] = 0x1F595, // 🖕
    [_MOYAI] = 0x1F5FF, // 🗿
    [_SALUTE] = 0x1FAE1, // 🫡
    [_SKULL] = 0x1F480, // 💀
    [_THINKING] = 0x1F914, // 🤔
    [_THUMB_UP] = 0x1F44D, // 👍
    [_THUMB_DOWN] = 0x1F44E, // 👎
};

// Non-emoji
#define DASH XP(_EN_DASH, _EM_DASH)
#define I_CIRC XP(_I_CIRCUMFLEX_LOWER, _I_CIRCUMFLEX_UPPER)

// Emoji
#define ALIEN X(_ALIEN)
#define DISGUISE X(_DISGUISED_FACE)
#define FIRE X(_FIRE)
#define GOAT X(_GOAT)
#define MOYAI X(_MOYAI)
#define MID_FING X(_MIDDLE_FINGER)
#define SKULL X(_SKULL)
#define THINK_SAL XP(_THINKING, _SALUTE)
#define THUMB XP(_THUMB_UP, _THUMB_DOWN)
