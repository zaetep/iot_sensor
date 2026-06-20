#include "main.h"

void vBlinkLED(void *pvParameters) {
    (void)pvParameters;

    for ( ;; ) {
        vTaskDelay(pdMS_TO_TICKS(500));
        BSP_LED_Toggle(LED_GREEN);
    }
}