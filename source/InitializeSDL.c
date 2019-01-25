#include "InitializeSDL.h"
#include "SDL.h"
#include "PlaySound.h"
#include "Figures.h"
#include <stdio.h>


int InitializeSDL(Window* sdlWindow)
{
    // Initialize SDL2 -> Video and Audio
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
    
    // Create an application window with the following settings:
    sdlWindow->window = SDL_CreateWindow(
                                          "Chess", // window title
                                          SDL_WINDOWPOS_UNDEFINED, // initial x position
                                          SDL_WINDOWPOS_UNDEFINED, // initial y position
                                          600,  // width, in pixels
                                          800,  // height, in pixels
                                          SDL_WINDOW_OPENGL  // flags - see below
                                          );
    
    // Check that the window was successfully created
    if (sdlWindow->window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create a renderer, surface and texture
    sdlWindow->renderer = SDL_CreateRenderer(sdlWindow->window, -1, 0);
    
    sdlWindow->chessField = SDL_LoadBMP("media/ChessField.bmp");
    sdlWindow->background = SDL_CreateTextureFromSurface(
            sdlWindow->renderer, sdlWindow->chessField);

    // Create additional white and black queen images
    SDL_Surface* wQueen = SDL_LoadBMP("media/W_Queen.bmp");
    sdlWindow->whiteQueen = SDL_CreateTextureFromSurface(
            sdlWindow->renderer, wQueen);
    SDL_FreeSurface(wQueen);

    SDL_Surface* bQueen = SDL_LoadBMP("media/B_Queen.bmp");
    sdlWindow->blackQueen = SDL_CreateTextureFromSurface(
            sdlWindow->renderer, bQueen);
    SDL_FreeSurface(bQueen);


    // After intializing all image data init sound
    LoadAudio(sdlWindow);
   
    return 0;
}


void CleanupSDL(
        Window* sdlWindow,
        Figure* figures,
        int count)
{
    // Clear the memory of all figures
    ClearFigureMemory(count, figures);
    
    // Clear all audio data
    SDL_CloseAudioDevice(sdlWindow->audioDevice);

    // Close and destroy the window
    if (sdlWindow->circle.texture != NULL)
        SDL_DestroyTexture(sdlWindow->circle.texture);

    if (sdlWindow->messageImages.xSymbol != NULL)
        SDL_DestroyTexture(sdlWindow->messageImages.xSymbol);
    if (sdlWindow->messageImages.bCheck != NULL)
        SDL_DestroyTexture(sdlWindow->messageImages.bCheck);
    if (sdlWindow->messageImages.wCheck != NULL)
        SDL_DestroyTexture(sdlWindow->messageImages.wCheck);

    SDL_DestroyTexture(sdlWindow->background);
    SDL_FreeSurface(sdlWindow->chessField);
    SDL_DestroyRenderer(sdlWindow->renderer);
    SDL_DestroyWindow(sdlWindow->window);
    
    // Clean up
    SDL_Quit();
}


