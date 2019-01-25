#include "InitializeDebug.h"

void InitializeDebugField(unsigned int field[][8][2], SpecialMoveSet *specialMoveSet)
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
            // Pawns
            if((rowcount == 1 && columnc < 4) || rowcount == 6)
                field[rowcount][columnc][0] = 1;

            // All other figures -> Last and first row
            else if(rowcount == 0 || rowcount == 7)
            {
                // Counting up the columns
                if(columnc < 5)
                    field[rowcount][columnc][0] = columnc + 2;

                else if(rowcount == 7)
                    field[rowcount][columnc][0] = 9 - columnc;
                else
                    field[rowcount][columnc][0] = 0;
            }
            // Reset everything to 0
            else
            {
                field[rowcount][columnc][0] = 0;
            }

            if(rowcount > 5)
                field[rowcount][columnc][1] = 1;                // weiße Farbe
            else
                field[rowcount][columnc][1] = 0;                // schwarz Farbe
            
            // Debug Castling
            field[0][7][0] = 2;
            field[3][5][0] = 4;
            field[3][5][1] = 1;
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


void InitializeDebugField2(unsigned int field[][8][2], SpecialMoveSet *specialMoveSet)
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
            // Pawns
            if((rowcount == 1 && columnc < 4) || rowcount == 6)
                field[rowcount][columnc][0] = 1;

            // All other figures -> Last and first row
            else if(rowcount == 0 || rowcount == 7)
            {
                // Counting up the columns
                if(columnc < 5)
                    field[rowcount][columnc][0] = columnc + 2;

                else if(rowcount == 7)
                    field[rowcount][columnc][0] = 9 - columnc;
                else
                    field[rowcount][columnc][0] = 0;
            }
            // Reset everything to 0
            else
            {
                field[rowcount][columnc][0] = 0;
            }

            if(rowcount > 5)
                field[rowcount][columnc][1] = 1;                // weiße Farbe
            else
                field[rowcount][columnc][1] = 0;                // schwarz Farbe
            
            // Debug Castling
            field[0][7][0] = 2;
            field[1][6][0] = 1;
            field[1][6][1] = 1;
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