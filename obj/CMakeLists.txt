add_library(Navigate INTERFACE)
#add_library(Camera INTERFACE)
add_library(Screen INTERFACE)
add_library(Glasses INTERFACE)

add_library(Scene INTERFACE)
add_library(Overlay INTERFACE)
add_library(Button INTERFACE)

#add_library(Storage INTERFACE)
#add_library(Image INTERFACE)
#add_library(Text INTERFACE)

target_sources(Navigate INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Navigate/Navigate.cpp)
#target_sources(Camera INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Camera/Camera.cpp)
target_sources(Screen INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Screen/Screen.cpp)
target_sources(Glasses INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Glasses/Glasses.cpp)

target_sources(Scene INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Scene/Scene.cpp)
target_sources(Overlay INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Overlay/Overlay.cpp)
target_sources(Button INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Button/Button.cpp)

#target_sources(Storage INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Storage/Storage.cpp)
#target_sources(Image INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Image/Image.cpp)
#target_sources(Text INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Text/Text.cpp)

target_include_directories(Navigate INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Navigate)
#target_include_directories(Camera INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Camera)
target_include_directories(Screen INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Screen)
target_include_directories(Glasses INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Glasses)

target_include_directories(Scene INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Scene)
target_include_directories(Overlay INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Overlay)
target_include_directories(Button INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Button)

#target_include_directories(Storage INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Storage)
#target_include_directories(Image INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Image)
#target_include_directories(Text INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Text)

target_link_libraries(Navigate INTERFACE pico_stdlib hardware_gpio)
#target_link_libraries(Camera INTERFACE pico_stdlib hardware_gpio)
target_link_libraries(Glasses INTERFACE pico_stdlib hardware_gpio)

target_link_libraries(Screen INTERFACE hardware_i2c pico_stdlib ssd1306)
target_link_libraries(Scene INTERFACE hardware_i2c pico_stdlib ssd1306)
target_link_libraries(Overlay INTERFACE hardware_i2c pico_stdlib ssd1306)
