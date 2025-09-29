#include <device.h>
#include <drivers/display.h>
#include <lvgl.h>

void oled_init(const struct device *dev) {
    display_blanking_off(dev);  // turn display on
}

void oled_update(const struct device *dev) {
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello ZMK!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_task_handler();
}
