#include <device.h>
#include <drivers/display.h>
#include <zephyr.h>

void main(void) {
    const struct device *dev = device_get_binding("SSD1306");
    if (!dev) {
        printk("Display not found!\n");
        return;
    }

    uint8_t buffer[8 * 128] = {0}; // 8 pages, 128 columns
    // Draw a simple pattern (fill top row)
    for (int i = 0; i < 128; i++) {
        buffer[i] = 0xFF;
    }

    display_write(dev, buffer, 0, 0, 128, 8);
}
