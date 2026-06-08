cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set project name
set(CMAKE_PROJECT_NAME iot_sensor)
project(${CMAKE_PROJECT_NAME})

# Allow policy for external linking of libraries
cmake_policy(SET CMP0079 NEW)

# Init Executable
add_executable(${CMAKE_PROJECT_NAME})

# Specify desired file name
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME "iot_sensor.elf")

# Add include directories
target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC
    src/inc
    freertos-kernel/include
    )

# Add STM32 HAL
add_subdirectory(stm32)

# Set FreeRTOS version
set(FREERTOS_PORT GCC_ARM_CM33_NTZ_NONSECURE CACHE STRING "FreeRTOS Port")
set(FREERTOS_HEAP 4)

# Define an INTERFACE target for FreeRTOSConfig.h
add_library(freertos_config INTERFACE)

# Point to the directory where FreeRTOSConfig.h is located
target_include_directories(
    freertos_config SYSTEM INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/config
)

target_compile_definitions(
    freertos_config
    INTERFACE
    projCOVERAGE_TEST=0)

# Add FreeRTOS Kernel
add_subdirectory(freertos-kernel)

# Add source directory
add_subdirectory(src)

target_link_libraries(
    ${PROJECT_NAME}
    freertos_kernel
    freertos_config
)

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    "LINKER:--script=${CMAKE_CURRENT_SOURCE_DIR}/stm32/STM32U545xx_FLASH.ld"
)