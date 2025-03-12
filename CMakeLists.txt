cmake_minimum_required(VERSION 3.16)

project(Digital_cookbook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Digital_cookbook main.cpp recipebook.cpp)  # Include both files

include(GNUInstallDirs)
install(TARGETS Digital_cookbook
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
