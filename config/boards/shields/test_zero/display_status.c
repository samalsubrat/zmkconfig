/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/status_screen.h>
#include <lvgl.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static lv_obj_t *zmk_display_status_screen;
static lv_obj_t *hello_label;

lv_obj_t *zmk_display_status_screen_obj() {
    if (zmk_display_status_screen == NULL) {
        // Create the main screen container
        zmk_display_status_screen = lv_obj_create(NULL);
        
        // Set background to black for monochrome OLED
        lv_obj_set_style_bg_color(zmk_display_status_screen, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(zmk_display_status_screen, LV_OPA_COVER, LV_PART_MAIN);
        
        // Remove padding and borders for full screen usage
        lv_obj_set_style_pad_all(zmk_display_status_screen, 0, LV_PART_MAIN);
        lv_obj_set_style_border_width(zmk_display_status_screen, 0, LV_PART_MAIN);
        
        // Create and configure the "HELLO WORLD!" label
        hello_label = lv_label_create(zmk_display_status_screen);
        
        // Set the text content
        lv_label_set_text(hello_label, "HELLO WORLD!");
        
        // Set text color to white for visibility on black background
        lv_obj_set_style_text_color(hello_label, lv_color_white(), LV_PART_MAIN);
        
        // Center the label on the screen
        lv_obj_center(hello_label);
        
        // Set text alignment to center
        lv_obj_set_style_text_align(hello_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
        
        LOG_DBG("Custom status screen initialized with HELLO WORLD label");
    }
    
    return zmk_display_status_screen;
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
