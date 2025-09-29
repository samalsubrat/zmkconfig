/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/status_screen.h>
#include <lvgl.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "HELLO");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    
    LOG_INF("Custom status screen created");
    
    return label;
}

// Optional: Function to update the text dynamically
void update_hello_text(const char *text) {
    if (hello_label != NULL) {
        lv_label_set_text(hello_label, text);
    }
}

// Optional: Function to update text color
void update_hello_color(lv_color_t color) {
    if (hello_label != NULL) {
        lv_obj_set_style_text_color(hello_label, color, LV_PART_MAIN);
    }
}
