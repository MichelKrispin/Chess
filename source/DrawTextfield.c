#include "DrawTextfield.h"
#include "SDL.h"

// message value is used for loading specified image
void DrawTextfield(Window* sdlWindow)
{
    char ShowMessage[50];
    switch (sdlWindow->message)
    {
        // Invalid move
        case 1:
            strcpy(ShowMessage, "media/1_XSymbol.bmp");
            break;

        // Check black
        case 2:
            strcpy(ShowMessage, "media/2_B_Check.bmp");
            break;

        // Check white
        case 3:
            strcpy(ShowMessage, "media/3_W_Check.bmp");
            break;
            
        default:
            break;
    }

    SDL_Surface* surfaceMessage = SDL_LoadBMP(ShowMessage); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(sdlWindow->renderer, surfaceMessage);

    SDL_FreeSurface(surfaceMessage);

    SDL_Rect TextfieldRect;
    TextfieldRect.x = 50;
    TextfieldRect.y = 650;
    TextfieldRect.w = 100;
    TextfieldRect.h = 100;


    SDL_RenderCopy(sdlWindow->renderer, Message, NULL, &TextfieldRect); 
}

