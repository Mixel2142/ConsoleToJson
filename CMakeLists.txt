cmake_minimum_required(VERSION 3.0.0)

project(ConsoleToJson_CMake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} "main.cpp" "myfunctions.h" "allheaders.h" "myfunctions.cpp" "jsonpack.cpp" "jsonpack.h")

target_link_libraries(${PROJECT_NAME} Qt5::Core -ljson-c -lreadline)
