#include "DrawTextfield.h"
#include "SDL.h"
#include <stdlib.h>

void AddToRenderer(Window* sdlWindow, SDL_Texture* texture)
{
    SDL_Rect TextfieldRect;
    TextfieldRect.x = 50;
    TextfieldRect.y = 650;
    TextfieldRect.w = 100;
    TextfieldRect.h = 100;


    SDL_RenderCopy(sdlWindow->renderer, texture, NULL, &TextfieldRect); 
}

// message value is used for loading specified image
void DrawTextfield(Window* sdlWindow)
{
    char ShowMessage[25];
    switch (sdlWindow->message)
    {
        // Invalid move
        case 1:
            if (sdlWindow->messageImages.xSymbol == NULL)
            {
                SDL_Surface* surfaceMessage = SDL_LoadBMP("media/1_XSymbol.bmp"); 
                sdlWindow->messageImages.xSymbol = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceMessage);

                SDL_FreeSurface(surfaceMessage);
            }
            else
                AddToRenderer(sdlWindow, sdlWindow->messageImages.xSymbol);
            break;

        // Check black
        case 2:
            if (sdlWindow->messageImages.bCheck == NULL)
            {
                SDL_Surface* surfaceMessage = SDL_LoadBMP("media/2_B_Check.bmp"); 
                sdlWindow->messageImages.bCheck = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceMessage);

                SDL_FreeSurface(surfaceMessage);
            }
            else
                AddToRenderer(sdlWindow, sdlWindow->messageImages.bCheck);
            break;

        // Check white
        case 3:
            if (sdlWindow->messageImages.wCheck == NULL)
            {
                SDL_Surface* surfaceMessage = SDL_LoadBMP("media/3_W_Check.bmp"); 
                sdlWindow->messageImages.wCheck = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceMessage);
 
                SDL_FreeSurface(surfaceMessage);
            }
            else
                AddToRenderer(sdlWindow, sdlWindow->messageImages.wCheck);
            break;
            
        default:
            return;
            break;
    }
}

