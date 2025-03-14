cmake_minimum_required(VERSION 3.16)

# Project Name
project(RecipeBook LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 (Ensure the correct path if necessary)
set(Qt6_DIR "C:/Qt/6.8.2/mingw_64/lib/cmake/Qt6")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable Qt's Automatic Code Generation
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Define source files
set(SOURCES
    src/main.cpp
    src/recipebook.cpp
    src/ui/mainwindow.cpp
)

set(UIS
    src/ui/mainwindow.ui
)

# Add Executable
add_executable(RecipeBook ${SOURCES} ${UIS})

# Include directories
target_include_directories(RecipeBook PRIVATE ${CMAKE_BINARY_DIR} include src)

# Link Qt6 Libraries
target_link_libraries(RecipeBook PRIVATE Qt6::Widgets)
