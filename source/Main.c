#include <string.h>
#include <stdlib.h>

#include "StructDefinitions.h"
#include "Initialize.h"
#include "PlaySound.h"
#include "Figures.h"
#include "InitializeSDL.h"
#include "DrawTextfield.h"
#include "Draw.h"
#include "DrawCircle.h"
#include "Move.h"
#include "CheckMove.h"
#include "CheckBlocked.h"
#include "CheckChecked.h"
#include "CheckLogic.h"
#include "CheckCheckmate.h"
#include "ShowMessageBox.h"

#ifdef main // Used for SDL on windows
#undef main
#endif /* main */

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
  
    Figures figures;
    figures.count = 32;
    figures.figures = InitializeFigures(&window);

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
    // Bool for checking if click was inside field
    char validClick = 1;
    
    Draw(field, &window, &figures, &mouse, &activePlayer);

    while (isPlaying)
    {
        // Check if the move is valid
        if (clickIndex == 0 && oneTimeChecking == 0 && validClick == 1)
        {
            oneTimeChecking = 1;
            isMovable = 1;
            if (!CheckMove(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
            {
                window.message = 1;
                //printf("Can't move this way\n");
                isMovable = 0;
            }
            // Check if logic is valid on this move
            if (!CheckLogic(activePlayer, startrow, startcolumn, destrow, destcolumn, field) && window.message != 1)
            {
                //printf("Invalid move\n");
                window.message = 1;
                isMovable = 0;
            }
        }

        // Reset oneTimeChecking and message
        if (clickIndex == 1)
        {
            oneTimeChecking = 0;
            window.message = 0;
        }
        
        // Check if last mouse is different from new mouse
        // If so transform to row and column space
        if (mouse.lastMouseX != mouse.newMouseX
         || mouse.lastMouseY != mouse.newMouseY)
        {
            if (clickIndex == 0 || clickIndex == -1)
            {
                TransformPixelToRowColumn(
                        mouse.newMouseX,
                        &startcolumn,
                        mouse.newMouseY,
                        &startrow);
                // Check if click was inside field
                if (startcolumn == 8 || startrow == 8)
                    validClick = 0;
                else
                    validClick = 1;

                if (validClick)
                {
                    window.circle.isSet = 1;
                    window.circle.row = startrow;
                    window.circle.column = startcolumn;
                }
            }

            else if (clickIndex == 1)
            {
                TransformPixelToRowColumn(
                        mouse.newMouseX,
                        &destcolumn,
                        mouse.newMouseY,
                        &destrow);
                // If click wasn't inside field click again
                if (destcolumn == 8 || destrow == 8)
                    validClick = 0;
                else
                    validClick = 1;

                if (validClick)
                    window.circle.isSet = 0;
            }

            if (startcolumn == destcolumn 
             && startrow    == destrow)
                oneTimeChecking = 1;

            mouse.lastMouseX = mouse.newMouseX;
            mouse.lastMouseY = mouse.newMouseY;

            if (clickIndex == -1)
                clickIndex = 1;
            else if (validClick)
                clickIndex = clickIndex ? 0 : 1;
        }
        
        // If everything is alright move the figure
        // The clickIndex needs to be 0 again
        // because two clicks are covered now
        if (clickIndex == 0 && isMovable == 1)
        {
            Move(startrow, startcolumn, destrow, destcolumn, field);
            // If any figure is moved play the sound
            PlaySound(&window);

            // Check if check or checkmate
            if (CheckChecked(field))
            {
                checkMate = CheckCheckmate(activePlayer, field);
                if(checkMate)
                {
                    if(checkMate == 1)
                    {
                        // CHECKMATE
                        if (activePlayer == 0)
                            window.message = 3;
                        else
                            window.message = 2;
                    }
                        //printf("Checkmate!\n");
                    else
                        window.message = 1;
                        //printf("Stalemate!\n");
                }
                else
                { 
                    // If active player is black then load W_Check
                    if (activePlayer == 0)
                        window.message = 3;
                    else
                        window.message = 2;
                    //printf("Check!\n");
                }
            }
            // Toggle active player
            activePlayer = activePlayer ? 0 : 1;
            isMovable = 0;
        }

        // Draw the field
        isPlaying = Draw(field,
                         &window,
                         &figures,
                         &mouse,
                         &activePlayer);
        
        // If checkMate is true show message box
        if (checkMate)
        {
            char message[100];
            // If active player is black -> Because it already swapped
            if (activePlayer == 0)
                strcpy(message, "White won! Play again?");
            else
                strcpy(message, "Black won! Play again?");
            int button = ShowMessageBox("Checkmate!", message);
            if (button == 0)
            {
               InitializeField(field); 
               activePlayer = 1;
               checkMate = 0;
               window.message = 0;
            }
            if (button == 1)
                isPlaying = 0;
        }
        
        // Prints Error for debug purposes
        //printf("%s\n", SDL_GetError());

    }

    // TODO: Cleanup all figures surfaces closeaudiodevice and freewav
    CleanupSDL(&window, figures.figures, figures.count);
    free(figures.figures);
    return 0;
}
