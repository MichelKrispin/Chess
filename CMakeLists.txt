cmake_minimum_required(VERSION 3.10.0)
project (Chess C)

if (WIN32)
    set(SDL2_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/sdl/include/SDL2/")
    set(SDL2_LIBRARIES "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2main.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.dll.a"
                       "${PROJECT_SOURCE_DIR}/sdl/lib/libSDL2.a")
elseif (APPLE)
    find_package(SDL2 REQUIRED)
else()
    INCLUDE(FindPkgConfig)
    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    set(SDL2_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/sdl/include/SDL2/")
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
           ./source/InitializeDebug.c
           ./source/InitializeSDL.c
           ./source/Move.c
           ./source/PlaySound.c
           ./source/ShowMessageBox.c
           ./source/CheckMove.c)


add_executable(Chess ${SOURCE})

target_include_directories(Chess PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Chess ${SDL2_LIBRARIES})

