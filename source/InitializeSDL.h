#include "SDL.h"

int InitializeSDL(Window* sdlWindow)
{
    
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    
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
   
    return 0;
}


void CleanupSDL(
        Window* sdlWindow,
        Figure* figures,
        int count)
{
    count = figures[0].imageInfo.x;

    // Clear the memory of all figures
    ClearFigureMemory(count, figures);
    
    // Close and destroy the window
    SDL_DestroyTexture(sdlWindow->background);
    SDL_FreeSurface(sdlWindow->chessField);
    SDL_DestroyRenderer(sdlWindow->renderer);
    SDL_DestroyWindow(sdlWindow->window);
    
    // Clean up
    SDL_Quit();
}

