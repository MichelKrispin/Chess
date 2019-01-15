#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#include "StructDefinitions.h"
#include "Initialize.h"
#include "Draw.h"
#include "CheckMove.h"
#include "CheckLogic.h"
#include "Move.h"
#include "CheckChecked.h"
#include "CheckCheckmate.h"
#include "Figures.h"
#include "InitializeSDL.h"


int main(int argsc, char* argv[])
{
    // Initialize array to 0
    unsigned int field[8][8][2];                          
    memset(field, 0, sizeof(field)); 

    // Initialize field array with data
    InitializeField(field);

    // Initialize SDL
    Window window;
    InitializeSDL(&window);

    // For the MousePosition
    MousePosition mouse = {0, 0, 0, 0};
    char clickIndex = -1; // If 0 first click 1 second click
  
    Figure figures[32];
    InitializeFigures(figures, &window);

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
    
    Draw(field, &window, figures, &mouse);

    while (isPlaying)
    {
        // Check if the move is valid
        if (clickIndex == 0 && oneTimeChecking == 0)
        {
            oneTimeChecking = 1;
            isMovable = 1;
            if (!CheckMove(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
            {
                printf("Can't move this way\n");
                isMovable = 0;
            }
            // Check if logic is valid on this move
            if (!CheckLogic(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
            {
                printf("Invalid move\n");
                isMovable = 0;
            }

            // Check if check or checkmate
            if (CheckChecked(activePlayer, field))
            {
                /*if(CheckCheckmate(field))
            {
                isPlaying = 0;
            }
            else
            {*/
                printf("Check!");
                //}
            }
        }

        // Reset oneTimeChecking
        if (clickIndex == 1)
            oneTimeChecking = 0;
        
        // Check if last mouse is different from new mouse
        // If so transform to row and column space
        if (mouse.lastMouseX != mouse.newMouseX
         || mouse.lastMouseY != mouse.newMouseY)
        {
            if (clickIndex == 0 || clickIndex == -1)
                TransformPixelToRowColumn(
                        mouse.newMouseX,
                        &startcolumn,
                        mouse.newMouseY,
                        &startrow);

            else if (clickIndex == 1)
                TransformPixelToRowColumn(
                        mouse.newMouseX,
                        &destcolumn,
                        mouse.newMouseY,
                        &destrow);

            mouse.lastMouseX = mouse.newMouseX;
            mouse.lastMouseY = mouse.newMouseY;

            if (clickIndex == -1)
                clickIndex = 1;
            else
                clickIndex = clickIndex ? 0 : 1;
        }
        
        // If everything is alright move the figure
        // The clickIndex needs to be 0 again
        // because two clicks are covered now
        if (clickIndex == 0 && isMovable == 1)
        {
            Move(startrow, startcolumn, destrow, destcolumn, field);
            // Toggle active player
            activePlayer = activePlayer ? 0 : 1;
            isMovable = 0;
        }

        // Draw the field
        isPlaying = Draw(field, &window, figures, &mouse);
        
        
        // Prints Error for debug purposes
        //printf("%s\n", SDL_GetError());

    }

    // TODO: Cleanup
    CleanupSDL(&window, figures, 32);
    return 0;
}
