// Copyright 2022 Pavel Glushkov (@pashutk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS  8
#define MATRIX_COLS  6

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#define TAPPING_TERM 250

/* disable action features */
#undef MASTER_LEFT
#define MASTER_RIGHT
