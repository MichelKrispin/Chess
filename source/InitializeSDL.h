#ifndef INITIALIZESDL_H
#define INITIALIZESDL_H

#include "SDL.h"
#include "StructDefinitions.h"

int InitializeSDL(Window* sdlWindow);

void CleanupSDL(
        Window* sdlWindow,
        Figure* figures,
        int count);

#endif
