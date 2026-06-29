/**
  ******************************************************************************
  * @file           : blinkLED.c
  * @brief          : Source file for LED related tasks.
  * @author         : Kaden Downes
  ******************************************************************************
  */

#include "main.h"

/**
 * @brief Task that toggles the onboard LED every 500 ms.
 */
void vBlinkLED(void *pvParameters) 
{
    (void)pvParameters;

    for ( ;; ) {
        vTaskDelay(pdMS_TO_TICKS(500));
        BSP_LED_Toggle(LED_GREEN);
    }
}