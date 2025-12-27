cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

project(mirea CXX)

add_executable(spinners src/spinners.cpp)
add_executable(spinners_again src/spinners_again.cpp)
add_executable(not_about_spinners src/not_about_spinners.cpp)
add_executable(wagon src/wagon.cpp)
add_executable(cinema src/cinema.cpp)

# Create a symlink from current "configure target" binary dir to the source root for LSPs like clangd
option(CREATE_COMPILE_COMMANDS_SYMLINK "Symlinks compile_commands.json from 'build' folder to the source tree root folder. Used by LSPs like clangd" ON)

if (CREATE_COMPILE_COMMANDS_SYMLINK AND EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
    file(CREATE_LINK
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
        SYMBOLIC
    )
endif()