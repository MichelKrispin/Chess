#ifndef STRUCTDEFINITIONS_H
#define STRUCTDEFINITIONS_H

#include "SDL.h"

typedef struct PositionCircle
{
    SDL_Texture* texture;
    unsigned int row;
    unsigned int column;
    char isSet;
} PositionCircle;

typedef struct MessageImages
{
    SDL_Texture* xSymbol;
    SDL_Texture* bCheck;
    SDL_Texture* wCheck;
} MessageImages;

typedef struct Window
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* chessField;
    SDL_Texture* background;
    SDL_Texture* whiteQueen;
    SDL_Texture* blackQueen;

    // Used to show specific symbol
    char message;
    MessageImages messageImages;

    // Used to show circle below clicked figure
    PositionCircle circle;
    
    // Used to save audio data
    SDL_AudioSpec spec;
    SDL_AudioDeviceID audioDevice;
    unsigned int audioLength;
    unsigned char* audioBuffer;

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

typedef struct Figures
{
    Figure* figures;
    int count;
} Figures;

typedef struct MousePosition
{
    int lastMouseX;
    int lastMouseY;
    int newMouseX;
    int newMouseY;
} MousePosition;

typedef struct SpecialMoveSet
{
    // for movechecks (to 1 when piece moved at least once)
    char bLeftRook;  // black left (white players viewpoint)
    char bRightRook; // black right
    char wLeftRook;  // white left
    char wRightRook; // white right
    char blackKing;
    char whiteKing;
    char enPassente; // pawns
    unsigned int enPassenteColumn;
} SpecialMoveSet;

#endif
