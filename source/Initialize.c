#include "Initialize.h"

void InitializeField(unsigned int field[][8][2], SpecialMoveSet *specialMoveSet)
{
    // Set all array elements to be either 0 as empty
    // Or numbers for different figure
    // Pawn  = 1
    // Tower = 2
    // Knight = 3
    // Bishop = 4
    // Queen = 5
    // King = 6
    // Third element indicates team color
    // -> 0 = Black
    // -> 1 = White

    for(unsigned int rowcount = 0; rowcount < 8; rowcount++)
    {
        for(unsigned int columnc = 0; columnc < 8; columnc++)
        {
            // Reset everything to 0
            field[rowcount][columnc][0] = 0;

            // Pawns
            if((rowcount == 1) || (rowcount == 6))
                field[rowcount][columnc][0] = 1;

            // All other figures -> Last and first row
            else if(rowcount == 0 || rowcount == 7)
            {
                // Counting up the columns
                if(columnc < 5)
                    field[rowcount][columnc][0] = columnc + 2;

                else
                    field[rowcount][columnc][0] = 9 - columnc;
            }
            if(rowcount > 5)
                field[rowcount][columnc][1] = 1;                // weiße Farbe
            else
                field[rowcount][columnc][1] = 0;                // schwarz Farbe
        }
    }

    // moved bools set to 0 and changed to 1 when piece moved once
    specialMoveSet->bLeftRook = 0; 
    specialMoveSet->bRightRook = 0; 
    specialMoveSet->wLeftRook = 0; 
    specialMoveSet->wRightRook = 0;
    specialMoveSet->blackKing = 0;
    specialMoveSet->whiteKing = 0;
    specialMoveSet->enPassente = 0; 
}
