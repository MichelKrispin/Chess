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
   
    unsigned int row;
    unsigned int column;

    // Bool saying whether game is still playing
    char isPlaying = 1;

    while (isPlaying)
    {
        if (!GetInput(&row, &column))
        {
            printf("Invalid input\n");
            continue;
        }

        // Check if logic is valid on this move
        if (!CheckLogic(row, column, field))
        {
            printf("Invalid move\n");
            continue;
        }
        // Check if the move is valid
        if (!CheckMove(row, column, field))
        {
            printf("Can't move this way\n");
            continue;
        }

        // If everything is allright move the figure
        Move(row, column, field);

        // Check if check or checkmate
        CheckCheckmate(row, column, field);

        // Draw the field
        Draw(field);
    }
    return 0;
}
