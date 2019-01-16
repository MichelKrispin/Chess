cmake_minimum_required(VERSION 3.11.0)
project (Chess C)

if (WIN32)
    set(SDL2_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/sdl/include/SDL2/")
    set(SDL2_LIBRARIES "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2main.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2_ttf.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2_ttf.dll.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.dll.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.a")
else()
    find_package(SDL2 REQUIRED)
endif()

set(SOURCE ./source/Main.c)


add_executable(Chess ./source/Main.c)

message(${SDL2_LIBRARIES})

target_include_directories(Chess PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Chess ${SDL2_LIBRARIES})

