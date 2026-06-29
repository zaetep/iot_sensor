#ifndef SHT3X_H
#define SHT3X_H

#include "main.h"

/* Definitions for functions with SHT3X Sensor over I2C */

#define SHT3X_ADDR_DEFAULT      (0x44 << 1)

#define SHT3X_SOFT_RESET        0x30A2
#define SHT3X_CLEAR_STATUS      0x3041
#define STH3X_MEAS_HIGH_NO_CS   0x2400

/* Export SHT3X Task for Initialization */

void vSHT3XTask(void *pvParameters);

#endif // SHT3X_H