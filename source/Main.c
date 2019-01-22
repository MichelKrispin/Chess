#include <stdio.h>
#include <wchar.h>
#include <locale.h>
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
    // outsourced variable initialization
    #include "Variables.h"

    memset(field, 0, sizeof(field)); 

    // Bools for moved at least once (enPassente and castling)
    SpecialMoveSet specialMoveSet;

    // Initialize field array with data    
    InitializeField(field, &specialMoveSet);

    // Initialize SDL
    Window window;
    InitializeSDL(&window);

    Figure figures[32];
    InitializeFigures(figures, &window);
    
    Draw(field, &window, figures, &mouse, &activePlayer, &specialMoveSet);

    while (isPlaying)
    {
        // Check if the move is valid
        if (clickIndex == 0 && oneTimeChecking == 0)
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
                window.circle.isSet = 1;
                window.circle.row = startrow;
                window.circle.column = startcolumn;
            }

            else if (clickIndex == 1)
            {
                TransformPixelToRowColumn(
                        mouse.newMouseX,
                        &destcolumn,
                        mouse.newMouseY,
                        &destrow);
                window.circle.isSet = 0;
            }

            if (startcolumn == destcolumn 
             && startrow    == destrow)
                oneTimeChecking = 1;

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
                         figures,
                         &mouse,
                         &activePlayer,
                         &specialMoveSet);
        
        // If checkMate is true show message box
        if (checkMate)
        {
            int button = ShowMessageBox();
            if (button == 0)
            {
               InitializeField(field, &specialMoveSet); 
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
    CleanupSDL(&window, figures, 32);
    return 0;
}
