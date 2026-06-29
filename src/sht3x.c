/**
  ******************************************************************************
  * @file           : sht3x.c
  * @brief          : Source file for SHT3X sensor functionality.
  * @author         : Kaden Downes
  ******************************************************************************
  */

#include "sht3x.h"

extern I2C_HandleTypeDef hi2c1;

/**
  *  @brief Send a command to the SHT3X sensor.
  *  @param command the 16-bit command to send.
  *  @retval Returns HAL status of the HAL function that sends the command.
  */
static HAL_StatusTypeDef SHT3X_Send_Command(uint16_t command) 
{
    uint8_t buf[2];
    buf[0] = (command >> 8) & 0xFF;
    buf[1] = command & 0xFF;

    return HAL_I2C_Master_Transmit(&hi2c1, SHT3X_ADDR_DEFAULT, buf, 2, HAL_MAX_DELAY);
}

/**
  *  @brief SHT3X Sensor Initialization Process
  */
void SHT3X_Init(void) 
{
    // 1. Wait for sensor to power on:
    // Sensor takes 0.5-1 ms to enter idle state.
    vTaskDelay(pdMS_TO_TICKS(2));

    // 2. Perform soft reset
    SHT3X_Send_Command(SHT3X_SOFT_RESET);
    vTaskDelay(pdMS_TO_TICKS(2));

    // 3. Clear status register (optional)
    SHT3X_Send_Command(SHT3X_CLEAR_STATUS);
    vTaskDelay(pdMS_TO_TICKS(1));
}