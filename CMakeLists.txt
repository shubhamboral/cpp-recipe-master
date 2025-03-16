cmake_minimum_required(VERSION 3.10)

project(RecipeBook)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(RecipeBook
    src/main.cpp
    src/recipebook.cpp
    src/ui/mainwindow.cpp
)

target_include_directories(RecipeBook PRIVATE src src/ui)

target_link_libraries(RecipeBook Qt6::Widgets)
