#ifndef DRAW_H
#define DRAW_H

#include "StructDefinitions.h"

void TransformRowColumnsToPixel(unsigned int row, unsigned int column,
                                int* xPixel, int* yPixel);

void TransformPixelToRowColumn(
        int  pixelInputX,
        unsigned int* columnOutput,
        int  pixelInputY,
        unsigned int* rowOutput);


int Draw(unsigned int field[8][8][2],
         Window* sdlWindow,
         Figure* figures,
         MousePosition* mouse,
         char* activePlayer);

#endif
