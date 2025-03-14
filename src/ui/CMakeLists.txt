cmake_minimum_required(VERSION 3.16)

# Add UI source files
add_library(ui_components
    mainwindow.cpp
)

# Link the Qt6 Widgets library
target_link_libraries(ui_components
    PRIVATE Qt6::Widgets
)

# Include directories
target_include_directories(ui_components PRIVATE ${CMAKE_SOURCE_DIR}/include)
