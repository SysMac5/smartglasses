cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(smartglasses C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(SMART_GLASSES_PATH ${PROJECT_SOURCE_DIR})

pico_sdk_init()

add_executable(smartglasses
    main.c
)

pico_enable_stdio_usb(smartglasses 1)
pico_enable_stdio_uart(smartglasses 1)

pico_add_extra_outputs(smartglasses)

add_subdirectory(lib)
#add_subdirectory(obj)

target_link_libraries(smartglasses pico_stdlib hardware_i2c ssd1306)
