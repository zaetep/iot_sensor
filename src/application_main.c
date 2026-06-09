#include "main.h"

void appEntryPoint(void) {
    // Initialize any tasks
    

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for ( ;; );
}