#ifndef VARIABLES_H
#define VARIABLES_H

#include "StructDefinitions.h"

// Initialize array to 0
unsigned int field[8][8][2];

// For the MousePosition
MousePosition mouse = {0, 0, 0, 0};
char clickIndex = -1; // If 0 first click 1 second click
    
// Intial rows and columns
unsigned int startrow = 0, startcolumn = 0;
unsigned int destrow = 0, destcolumn = 0;

// Bool saying whether game is still playing
char isPlaying = 1;

// Bool indicating the active player (White=1, Black=0)
char activePlayer = 1;

// Bool for checking only once
char oneTimeChecking = 0;

// Bool for isMovable
char isMovable = 0;

// Bool for checkmate
char checkMate = 0;

// Bool for Castling
char castling = 0;

// Bool for checking if click was inside field
char validClick = 1;

#endif