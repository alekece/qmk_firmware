/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
 
// #define USE_I2C
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_SLEEP // Turn off RGB light when host is asleep.
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 12
#define RGBLIGHT_SAT_STEP 25
#define RGBLIGHT_VAL_STEP 12

#define TAPPING_TERM 150
#define RETRO_TAPPING
#define PERMISSIVE_HOLD

#define MOUSEKEY_DELAY              100
#define MOUSEKEY_INTERVAL           30
#define MOUSEKEY_MAX_SPEED          6
#define MOUSEKEY_TIME_TO_MAX        10
#define MOUSEKEY_WHEEL_MAX_SPEED    8
#define MOUSEKEY_WHEEL_TIME_TO_MAX  40
