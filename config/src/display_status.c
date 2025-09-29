#include <zephyr/device.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <zmk/display/status_screen.h>

LV_FONT_DECLARE(lv_font_montserrat_16); // built-in font

// Function called to draw on OLED
static void oled_update(struct device *dev) {
    // Clear screen
    lv_obj_clean(lv_scr_act());

    // Create a label and center it
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello ZMK!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // Refresh display
    lv_disp_flush_ready(lv_disp_get_default());
}

// Register this as a status screen
ZMK_DISPLAY_SCREEN(oled_screen, oled_update);
