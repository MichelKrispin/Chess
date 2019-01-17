#ifndef FIGURES_H
#define FIGURES_H

#include "SDL.h"
#include "StructDefinitions.h"

Figure CreateFigureAt(char type[2], const char* imagePath, SDL_Renderer* renderer);


void RenderFigures(int count, Figure* figures, SDL_Renderer* renderer);


// Initializes all figures
void InitializeFigures(Figure* figures, Window* sdlWindow);


void ClearFigureMemory(int count, Figure* figures);

#endif
