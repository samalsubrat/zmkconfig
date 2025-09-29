#include <zephyr/kernel.h>
#include <zmk/display.h>
#include <lvgl.h>

LV_FONT_DECLARE(lv_font_montserrat_14);

int display_hello(struct zmk_display *disp) {
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "HELLO");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_update_layout(label);

    lv_task_handler();
    return 0;
}

ZMK_DISPLAY_STATUS_SCREEN(disp_hello, display_hello);
