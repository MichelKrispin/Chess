cmake_minimum_required(VERSION 3.11.0)
project (Chess C)

if (WIN32)
    set(SDL2_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/sdl/include/SDL2/")
    set(SDL2_LIBRARIES "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2main.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.dll.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.a")
else()
    find_package(SDL2 REQUIRED)
endif()

set(SOURCE ./source/Main.c
           ./source/CheckBlocked.c
           ./source/CheckCastling.c
           ./source/CheckChecked.c
           ./source/CheckCheckmate.c
           ./source/CheckLogic.c
           ./source/CheckMove.c
           ./source/Draw.c
           ./source/DrawCircle.c
           ./source/DrawTextfield.c
           ./source/Figures.c
           ./source/Initialize.c
           ./source/InitializeSDL.c
           ./source/Move.c
           ./source/PlaySound.c
           ./source/ShowMessageBox.c
           ./source/CheckMove.c)


add_executable(Chess ${SOURCE})

message(${SDL2_LIBRARIES})

target_include_directories(Chess PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Chess ${SDL2_LIBRARIES})

