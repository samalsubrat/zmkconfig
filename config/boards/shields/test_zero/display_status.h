/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

// Function declarations for the custom status screen
lv_obj_t *zmk_display_status_screen_obj(void);

// Optional utility functions for dynamic updates
void update_hello_text(const char *text);
void update_hello_color(lv_color_t color);

// Common colors for monochrome OLED
#define STATUS_SCREEN_COLOR_BLACK lv_color_black()
#define STATUS_SCREEN_COLOR_WHITE lv_color_white()