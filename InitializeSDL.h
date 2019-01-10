#include "include/SDL2/SDL.h"

typedef struct Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* chessField;
    SDL_Texture* background;
} Window;


int InitializeSDL(
        Window* sdlWindow,
        Figure* figures, int count)
{
    
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    
    // Create an application window with the following settings:
    sdlWindow->window = SDL_CreateWindow(
                                          "Chess",                 // window title
                                          SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                          SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                          600,                               // width, in pixels
                                          600,                               // height, in pixels
                                          SDL_WINDOW_OPENGL                  // flags - see below
                                          );
    
    // Check that the window was successfully created
    if (sdlWindow->window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create a renderer, surface and texture
    sdlWindow->renderer = SDL_CreateRenderer(sdlWindow->window, -1, 0);
    
    sdlWindow->chessField = SDL_LoadBMP("media/ChessField.bmp");
    sdlWindow->background = SDL_CreateTextureFromSurface(sdlWindow->renderer, sdlWindow->chessField);
    
    
    // Initialize figures
    figures[0] = CreateFigureAt("media/W_Pawn.bmp", 10, 10, sdlWindow->renderer);
    figures[1] = CreateFigureAt("media/W_Tower.bmp", 45, 10, sdlWindow->renderer);
    figures[2] = CreateFigureAt("media/W_Knight.bmp", 80, 10, sdlWindow->renderer);
    figures[3] = CreateFigureAt("media/W_Bishop.bmp", 115, 10, sdlWindow->renderer);
    figures[4] = CreateFigureAt("media/W_Queen.bmp", 150, 10, sdlWindow->renderer);
    figures[5] = CreateFigureAt("media/W_King.bmp", 15, 200, sdlWindow->renderer);
    figures[6] = CreateFigureAt("media/B_Pawn.bmp", 10, 50, sdlWindow->renderer);
    figures[7] = CreateFigureAt("media/B_Tower.bmp", 45, 50, sdlWindow->renderer);
    figures[8] = CreateFigureAt("media/B_Knight.bmp", 80, 50, sdlWindow->renderer);
    figures[9] = CreateFigureAt("media/B_Bishop.bmp", 115, 50, sdlWindow->renderer);
    figures[10] = CreateFigureAt("media/B_Queen.bmp", 150, 50, sdlWindow->renderer);
    figures[11] = CreateFigureAt("media/B_King.bmp", 185, 50, sdlWindow->renderer);

    count = 0;

    return 0;
}

int RenderOnScreen(Window* sdlWindow, Figure *figures)
{
    SDL_Event event;

    // Poll events
    SDL_PollEvent(&event);
    // Handle events
    switch(event.type)
    {
        case SDL_QUIT:
        return 0;
        break;
    }
    
    SDL_RenderCopy(sdlWindow->renderer, sdlWindow->background, NULL, NULL);
    
    //RenderFigures(12, figures, sdlWindow->renderer);
    SDL_RenderPresent(sdlWindow->renderer);
    
    SDL_Delay(16);
    return 1;
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

