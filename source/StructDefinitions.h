#include "SDL.h"

typedef struct Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* chessField;
    SDL_Texture* background;
    SDL_Texture* whiteQueen;
    SDL_Texture* blackQueen;
    char Message[50];
} Window;

typedef struct Figure
{
    SDL_Surface* image;
    SDL_Texture* texture;
    // Contains x, y, w, h
    SDL_Rect imageInfo;
    // Used for identifying the figure i.e. wp for white pawn
    char type[2];
    char isSet;
} Figure;

typedef struct MousePosition
{
    int lastMouseX;
    int lastMouseY;
    int newMouseX;
    int newMouseY;
} MousePosition;
