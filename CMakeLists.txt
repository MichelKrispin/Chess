cmake_minimum_required(VERSION 3.11.0)
project (Chess C)

find_package(SDL2 REQUIRED)
include_directories(Chess ${SDL2_INCLUDE_DIRS})

add_executable(Chess ./source/Main.c)
target_link_libraries(Chess ${SDL2_LIBRARIES})

