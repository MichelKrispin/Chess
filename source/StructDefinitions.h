#include "SDL.h"

typedef struct PositionCircle
{
    unsigned int row;
    unsigned int column;
    char isSet;
} PositionCircle;


typedef struct Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* chessField;
    SDL_Texture* background;
    SDL_Texture* whiteQueen;
    SDL_Texture* blackQueen;
    char message;
    PositionCircle circle;
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
