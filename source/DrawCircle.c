#include "DrawCircle.h"
#include "Draw.h"
#include "SDL.h"

// message value is used for loading specified image
void DrawCircle(Window* sdlWindow)
{
    SDL_Surface* surfaceCircle = SDL_LoadBMP("media/PositionCircle.bmp"); 

    SDL_Texture* circle = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceCircle);

    SDL_FreeSurface(surfaceCircle);

    SDL_Rect Rect;
    TransformRowColumnsToPixel(
            sdlWindow->circle.row,
            sdlWindow->circle.column,
            &Rect.x,
            &Rect.y);

    // Now adjust the x and y a little
    Rect.x -= 7;
    Rect.y -= 7;

    Rect.w = 70;
    Rect.h = 70;


    SDL_RenderCopy(sdlWindow->renderer, circle, NULL, &Rect); 
}



