# Toolchain file for STM32 (Cortex-M33) using GNU ARM toolchain

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Prevent CMake from trying to run/link a test executable
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Compilers
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Assembly compile object rule
set(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT> -c <SOURCE>")

# CPU/FPU flags
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m33 -mthumb -x assembler-with-cpp")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

message("Processing toolchain file")