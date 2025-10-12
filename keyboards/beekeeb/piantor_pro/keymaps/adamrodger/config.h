/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2024 Adam Rodger

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

#define VIAL_KEYBOARD_UID {0x72, 0xD1, 0xB2, 0x31, 0x83, 0x84, 0x13, 0xDE}

// Vial security combo
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* Select hand configuration */
//#define MASTER_LEFT
//#define MASTER_RIGHT
#define SPLIT_USB_DETECT

//#define USE_MATRIX_I2C

#define PERMISSIVE_HOLD
#ifndef CHORDAL_HOLD
  #define CHORDAL_HOLD
#endif
//#define TAPPING_TERM 100
