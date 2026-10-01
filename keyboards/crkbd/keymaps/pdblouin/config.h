/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

#define SPLIT_LAYER_STATE_ENABLE

#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#define TAPPING_TERM 250
#define PERMISSIVE_HOLD  // Triggers mod if you tap another key while holding.
#define CHORDAL_HOLD     // Constrains holds to opposite-hand combinations.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #define FLOW_TAP_TERM 150 // Disables holds when typing quickly.

// ── Constants ────────────────────────────────────────
#define _BASE 0
#define _NUM  1
#define _SYM  2
#define _RGB  3


