#include "main.h"
#include "alltasks.h"

void appEntryPoint(void) {
    // Initialize any tasks
    if (xTaskCreate(vBlinkLED, (const char *)"BlinkLED", configMINIMAL_STACK_SIZE, 
                    NULL, tskIDLE_PRIORITY + 1, NULL) != pdTRUE) {
        for ( ;; ); // error encountered
    }

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for ( ;; );
}