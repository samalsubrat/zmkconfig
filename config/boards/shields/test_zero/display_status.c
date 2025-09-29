#include <zmk/display/status_screen.h>
#include <lvgl.h>


lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *label = lv_label_create(lv_scr_act());   // Create a label
    lv_label_set_text(label, "HELLO WORLD!");          // Set the text
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);        // Center it
    return label;
}
