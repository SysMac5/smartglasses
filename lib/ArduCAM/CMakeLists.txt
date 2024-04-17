add_library(ArduCAM INTERFACE)

target_sources(ArduCAM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/ArduCAM.cpp
)

target_include_directories(ArduCAM INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(ArduCAM INTERFACE pico_stdlib hardware_i2c hardware_spi hardware_irq hardware_dma)
