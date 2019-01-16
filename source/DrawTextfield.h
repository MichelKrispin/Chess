#include "SDL.h"
#include "SDL_ttf.h"

void DrawTextfield(Window* sdlWindow)
{
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    SDL_Color White = {0, 0, 0};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, sdlWindow->Message, White); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceMessage);

    SDL_FreeSurface(surfaceMessage);

    SDL_Rect TextfieldRect;
    TextfieldRect.x = 50;
    TextfieldRect.y = 650;
    TextfieldRect.w = 400;
    TextfieldRect.h = 100;


    SDL_RenderCopy(sdlWindow->renderer, Message, NULL, &TextfieldRect); 
}
