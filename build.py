# build.py
# automated build + flash process

import os
import sys
import subprocess

BUILD_DIR = "build"
FIRMWARE_ELF = os.path.join(BUILD_DIR, "iot_sensor.elf")

def run(cmd):
    print(f"-> {cmd}")
    subprocess.run(cmd, check=True)

def build():
    run(["cmake", "--preset", "arm-gcc"])
    run(["cmake", "--build", BUILD_DIR, ])

def flash():
    if not os.path.exists(FIRMWARE_ELF):
        print("Firmware not found.")
        sys.exit(1)
    
    run(["STM32_Programmer_CLI", "-c", "port=SWD", "-d", FIRMWARE_ELF, "-v", "-rst"])

if __name__ == "__main__":
    build()
    flash()