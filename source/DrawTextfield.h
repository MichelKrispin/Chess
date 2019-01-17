#include "SDL.h"

// message value is used for loading specified image
void DrawTextfield(Window* sdlWindow)
{
    char ShowMessage[50];
    switch (sdlWindow->message)
    {
        // Can't move
        case 1:
            strcpy(ShowMessage, "media/1_Cantmove.bmp");
            break;

        // Invalid move
        case 2:
            strcpy(ShowMessage, "media/2_Invalidmove.bmp");
            break;

        // Checkmate
        case 3:
            strcpy(ShowMessage, "media/3_Checkmate.bmp");
            break;
            
        // Stalemate
        case 4:
            strcpy(ShowMessage, "media/4_Stalemate.bmp");
            break;

        // Check
        case 5:
            strcpy(ShowMessage, "media/5_Check.bmp");
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
    TextfieldRect.w = 350;
    TextfieldRect.h = 100;


    SDL_RenderCopy(sdlWindow->renderer, Message, NULL, &TextfieldRect); 
}
