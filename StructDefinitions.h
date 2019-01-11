#include "SDL2/SDL.h"

typedef struct Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* chessField;
    SDL_Texture* background;
} Window;

typedef struct Figure
{
    SDL_Surface* image;
    SDL_Texture* texture;
    // Contains x, y, w, h
    SDL_Rect imageInfo;
    char type[2]; // Used for identifying the figure i.e. wp for white pawn
    char isSet;
} Figure;


