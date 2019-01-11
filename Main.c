#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#include "StructDefinitions.h"
#include "ConsoleColors.h"
#include "Draw.h"
#include "Initialize.h"
#include "CheckMove.h"
#include "CheckLogic.h"
#include "Move.h"
#include "CheckCheckmate.h"
#include "GetInput.h"
#include "Figures.h"
#include "InitializeSDL.h"


int main()
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
  
    Figure figures[32];
    InitializeFigures(figures, &window);

    // Intial rows and columns
    unsigned int startrow = 0, startcolumn = 0;
    unsigned int destrow = 0, destcolumn = 0;

    // Bool saying whether game is still playing
    char isPlaying = 1;
    // Bool indicating the active player (White=1, Black=0)
    char activePlayer = 1;

    
    Draw(field, &window, figures, &mouse);

    while (isPlaying)
    {
        
        // Input is not taken at this moment
        int inputCode = 1; //GetInput(&startrow, &startcolumn, &destrow, &destcolumn);
        if (!inputCode)
        {
            printf("Invalid input\n");
            continue;
        } else if (inputCode == 2)
        {
            isPlaying = 0;
        } else if (inputCode == 2)
        {
            printf("%s gives up!\n %s wins!\n",
                     activePlayer ? "White" : "Black",
                     activePlayer ? "Black" : "White" );
            isPlaying = 0;
        }


        // Check if the move is valid
        if (!CheckMove(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
        {
            printf("Can't move this way\n");
            continue;
        }
        // Check if logic is valid on this move
        if (!CheckLogic(startrow, startcolumn, destrow, destcolumn, field))
        {
            printf("Invalid move\n");
            continue;
        }

        // TODO: DOESN'T WORK RIGHT NOW
        // Changes it every time 
        // Check if last mouse is different from new mouse
        // If so transform to row and column space
        if (mouse.lastMouseX != mouse.newMouseX
         || mouse.lastMouseY != mouse.newMouseY)
        {
            TransformPixelToRowColumn(
                    mouse.lastMouseX,
                    &startrow,
                    mouse.lastMouseY,
                    &startcolumn);

            TransformPixelToRowColumn(
                    mouse.newMouseX,
                    &destrow,
                    mouse.newMouseY,
                    &destcolumn);
            mouse.lastMouseX = mouse.newMouseX;
            mouse.lastMouseY = mouse.newMouseY;
        }
        //printf("startrow: %u, startcol: %u\ndestrow: %u, destcol: %u",
        //        startrow, startcolumn, destrow, destcolumn);
        
        // If everything is allright move the figure
        Move(startrow, startcolumn, destrow, destcolumn, field);

        // Check if check or checkmate
        CheckCheckmate(field);

       

        // Draw the field
        isPlaying = Draw(field, &window, figures, &mouse);
        
        
        // Prints Error for debug purposes
        //printf("%s\n", SDL_GetError());

        // Toggle active player
        activePlayer = activePlayer ? 1 : 0;
    }

    CleanupSDL(&window, figures, 32);
    return 0;
}
