#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#include "ConsoleColors.h"
#include "Draw.h"
#include "Initialize.h"
#include "CheckMove.h"
#include "CheckLogic.h"
#include "Move.h"
#include "CheckCheckmate.h"
#include "GetInput.h"

int main()
{
    // Initialize array to 0
    unsigned int field[8][8][2];                          
    memset(field, 0, sizeof(field)); 

    // Initialize field array with data
    InitializeField(field);
   
    unsigned int startrow, startcolumn;
    unsigned int destrow, destcolumn;

    // Bool saying whether game is still playing
    char isPlaying = 1;
    // Bool indicating the active player (White=1, Black=0)
    char activePlayer = 1;

    // Draw the field once
    Draw(field);
    

    while (isPlaying)
    {
        int inputCode = GetInput(&startrow, &startcolumn, &destrow, &destcolumn);
        // 0 = invalid input
        if (inputCode == 0)
        {
            COLOR_RED;
            printf("Invalid input\n");
            continue;
        } else if (inputCode == 2) // 2 = exitcode
        {
            isPlaying = 0;
            continue;
        } else if (inputCode == 3) // 3 = player gives up
        {
            COLOR_GREEN;
            printf("%s gives up!\n%s wins!\n",
                     (activePlayer == 1 ? "White" : "Black"),
                     (activePlayer == 1 ? "Black" : "White"));
            isPlaying = 0;
        }


        // Check if logic is valid on this move
        if (!CheckLogic(startrow, startcolumn,
                        destrow, destcolumn, field))
        {
            printf("Invalid move\n");
            continue;
        }
        // Check if the move is valid
        if (!CheckMove(activePlayer, startrow, startcolumn,
                       destrow, destcolumn, field))
        {
            printf("Can't move this way\n");
            continue;
        }

        // If everything is allright move the figure
        Move(startrow, startcolumn, destrow, destcolumn, field);

        // Check if check or checkmate
        CheckCheckmate(field);

        // Draw the field
        Draw(field);

        // Swap active player
        activePlayer = (activePlayer == 0 ? 1 : 0);
    }
    return 0;
}
