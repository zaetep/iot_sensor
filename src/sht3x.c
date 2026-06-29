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
static void SHT3X_Init(void) 
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

/**
  * @brief Start measurement from SHT3X sensor.
  */
static HAL_StatusTypeDef SHT3X_Start_Measurement(void)
{
    // Measure High Repeatability No Clock Stretching
    return SHT3X_Send_Command(STH3X_MEAS_HIGH_NO_CS);
}

/**
  * @brief Read measurement from SHT3X sensor.
  * @param *temperature Pointer to a `float` variable to store temperature data.
  * @param *humidity    Pointer to a `float` variable to store humidity data.
  * @retval Returns `HAL_StatusTypeDef` result of I2C communication.   
  */
static HAL_StatusTypeDef SHT3X_Read_Measurement(float *temperature, float *humidity)
{
    uint8_t data[6];

    HAL_StatusTypeDef status =
        HAL_I2C_Master_Receive(&hi2c1, SHT3X_ADDR_DEFAULT, data, 6, HAL_MAX_DELAY);

    if (status != HAL_OK) 
    {
        return status;
    }

    uint16_t rawTemperature = (data[0] << 8) | data[1];
    uint16_t rawHumidity = (data[3] << 8) | data[4];

    // Convert using datasheet formulas
    *temperature = -45.0f + (175.0f * (float)rawTemperature / 65535.0f);
    *humidity    = 100.0f * (float)rawHumidity / 65535.0f;

    return HAL_OK;
}

/**
 * @brief Task handling SHT3X functionality.
 */
void vSHT3XTask(void *pvParameters)
{
    // Perform initialization process.
    SHT3X_Init();

    for ( ;; )
    {

    }
}