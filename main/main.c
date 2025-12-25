#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#define In1 4
#define In2 5
void init_pins();

void app_main(void)
{
    init_pins();
    while(true) {
        // rotate CC
        gpio_set_level(In1, true);
        gpio_set_level(In2, false);
        vTaskDelay(pdMS_TO_TICKS(100));
        //stop
        gpio_set_level(In1, false);
        gpio_set_level(In2, false);
        vTaskDelay(pdMS_TO_TICKS(100));
        // rotate CCW
        gpio_set_level(In1, false);
        gpio_set_level(In2, true);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void init_pins() {
    gpio_reset_pin(In1);
    gpio_reset_pin(In2);
    gpio_set_direction(In1, GPIO_MODE_OUTPUT);
    gpio_set_direction(In2, GPIO_MODE_OUTPUT);
}