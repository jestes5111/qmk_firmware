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
    // Letter-like
    UNI_I_CIRCUMFLEX_LOWER,
    UNI_I_CIRCUMFLEX_UPPER,

    // Emoji
    UNI_ALIEN,
    UNI_DISGUISED_FACE,
    UNI_FIRE,
    UNI_GOAT,
    UNI_MIDDLE_FINGER,
    UNI_MOYAI,
    UNI_SALUTE,
    UNI_SKULL,
    UNI_THINKING,
    UNI_THUMB_UP,
    UNI_THUMB_DOWN,
};

const uint32_t unicode_map[] PROGMEM = {
    // Letter-like
    [UNI_I_CIRCUMFLEX_LOWER] = 0x00EE, // î
    [UNI_I_CIRCUMFLEX_UPPER] = 0x00CE, // Î

    // Emoji
    [UNI_ALIEN] = 0x1F47D, // 👽
    [UNI_DISGUISED_FACE] = 0x1F978, // 🥸
    [UNI_FIRE] = 0x1F525, // 🔥
    [UNI_GOAT] = 0x1F98C, // 🦌
    [UNI_MIDDLE_FINGER] = 0x1F595, // 🖕
    [UNI_MOYAI] = 0x1F5FF, // 🗿
    [UNI_SALUTE] = 0x1FAE1, // 🫡
    [UNI_SKULL] = 0x1F480, // 💀
    [UNI_THINKING] = 0x1F914, // 🤔
    [UNI_THUMB_UP] = 0x1F44D, // 👍
    [UNI_THUMB_DOWN] = 0x1F44E, // 👎
};

// Letter-like
#define I_CIRC XP(UNI_I_CIRCUMFLEX_LOWER, UNI_I_CIRCUMFLEX_UPPER)

// Emoji
#define ALIEN X(UNI_ALIEN)
#define DISGUISE X(UNI_DISGUISED_FACE)
#define FIRE X(UNI_FIRE)
#define GOAT X(UNI_GOAT)
#define MOYAI X(UNI_MOYAI)
#define MID_FING X(UNI_MIDDLE_FINGER)
#define SKULL X(UNI_SKULL)
#define THINK_SAL XP(UNI_THINKING, UNI_SALUTE)
#define THUMB XP(UNI_THUMB_UP, UNI_THUMB_DOWN)
