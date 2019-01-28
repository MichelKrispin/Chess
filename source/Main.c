#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "StructDefinitions.h"
#include "Initialize.h"
#include "InitializeDebug.h"
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
    SpecialMoveSet specialMoveSet = {};

    // Initialize field array with data   
    InitializeField(field, &specialMoveSet);

    // Initialize SDL
    Window window = {};
    InitializeSDL(&window);
      
    Figures figures;
    figures.count = 32;
    figures.figures = InitializeFigures(&window);
    
    Draw(field, &window, &figures, &mouse, &activePlayer, &specialMoveSet);

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
            if (!window.message && !CheckLogic(activePlayer, startrow, startcolumn, destrow, destcolumn, field, &specialMoveSet) && window.message != 1)
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
            // moves the turret aswell when castling
            if(field[startrow][startcolumn][0] == 6
               && abs((int)destcolumn - (int)startcolumn) == 2)
            {
                // white
                if(activePlayer)
                {
                    // right
                    if(destcolumn > 4)
                        Move(7, 7, 7, 5, field, &specialMoveSet);
                    // left
                    else
                        Move(7, 0, 7, 3, field, &specialMoveSet);
                }
                // black
                else
                {
                    // right
                    if(destcolumn > 4)
                        Move(0, 7, 0, 5, field, &specialMoveSet);
                    // left
                    else
                        Move(0, 0, 0, 3, field, &specialMoveSet);
                }
                PlaySound(&window);
                Move(startrow, startcolumn, destrow, destcolumn, field, &specialMoveSet);
            }
            // valid enPassente move
            else if(specialMoveSet.enPassente)
            {
                // first takes pawn to side, second moves to empty field behind
                Move(startrow, startcolumn, startrow, destcolumn, field, &specialMoveSet);
                Move(startrow, destcolumn, destrow, destcolumn, field, &specialMoveSet);
            }
            // any other move
            else
            {
                Move(startrow, startcolumn, destrow, destcolumn, field, &specialMoveSet);
            }

            // swaps pawn when reaching the endrow
            if(field[destrow][destcolumn][0] == 1
               && (destrow == 0 || destrow == 7))
            {
                field[destrow][destcolumn][0] = ShowSwapMessageBox();
                char figureType[2] = {'0','0'};
                switch (field[destrow][destcolumn][0])
                {
                    case 5:
                        figureType[1] = 'q';
                    break;
                    case 2:
                        figureType[1] = 'r';
                    break;
                    case 4:
                        figureType[1] = 'b';
                    break;
                    case 3:
                        figureType[1] = 'n';
                    break;
                }
                if (field[destrow][destcolumn][1] == 1)
                    figureType[0] = 'w';
                else
                    figureType[0] = 'b';
                figures.figures = AddFigure(&figures, figureType, &window);
            }
            
            // If any figure is moved play the sound
            PlaySound(&window);

            // Check if check or checkmate
            if (CheckChecked(field))
            {
                checkMate = CheckCheckmate(activePlayer, field, specialMoveSet);
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
                         &activePlayer,
                         &specialMoveSet);
        
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

    CleanupSDL(&window, figures.figures, figures.count);
    free(figures.figures);
    return 0;
}
