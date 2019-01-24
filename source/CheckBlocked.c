#include "CheckBlocked.h"
#include <stdlib.h>

// used for rook and queen
int Rook(unsigned int startrow, unsigned int startcolumn, 
         unsigned int destrow, unsigned int destcolumn, 
         unsigned int field[][8][2])
{
    // row and column addition variable added every loop
    int rookadd = (destrow < startrow) || (destcolumn < startcolumn) ? -1 : 1;
    unsigned int rookcount = 1;
    // for move along the column
    if (destrow == startrow)
    {
        // checking every field in column
        for (; (int)rookcount < abs((int)destcolumn - (int)startcolumn); rookcount++)
        {
            if (field[destrow][startcolumn + rookcount * rookadd][0])
                return 0;
        }
    }
    // for along the row
    else
    {
        // every field in row
        for (; (int)rookcount < abs((int)destrow - (int)startrow); rookcount++)
        {
            if (field[startrow + rookcount * rookadd][destcolumn][0])
                return 0;
        }
    }
    return 1;
}

// used for bishop and queen
int Bishop(unsigned int startrow, unsigned int startcolumn, 
           unsigned int destrow, unsigned int destcolumn, 
           unsigned int field[][8][2])
{
    // row and column addition variables added every loop
    int bishoprowadd = destrow > startrow ? 1 : -1;
    int bishopcoladd = destcolumn > startcolumn ? 1 : -1;
    // checks every field in diagonal
    for (unsigned int bishopcount = 1; (int)bishopcount < abs((int)destrow - (int)startrow); bishopcount++)
    {
        // both added simultaneously
        if (field[startrow + bishopcount * bishoprowadd][startcolumn + bishopcount * bishopcoladd][0])
            return 0;
    }
    return 1;
}

// checks for a piece in the way of the players move
int CheckBlocked(char activePlayer, 
                 unsigned int startrow, unsigned int startcolumn, 
                 unsigned int destrow, unsigned int destcolumn, 
                 unsigned int field[][8][2])
{
    // checks for own piece in destination
    if(field[destrow][destcolumn][0] && 
      (field[destrow][destcolumn][1] == (unsigned int)activePlayer))
        return 0;
    switch(field[startrow][startcolumn][0])
    {
        // Pawn
        case 1:
            if(destcolumn == startcolumn)
            {
                // checks for piece in destination
                if(field[destrow][destcolumn][0])
                    return 0;
                // if moving 2 fields
                else if((abs((int)destrow - (int)startrow) == 2) && 
                        field[(destrow + startrow) / 2][destcolumn][0])
                    return 0;
            }
            break;
        // Rook
        case 2:
            if (!Rook(startrow, startcolumn, destrow, destcolumn, field))
                return 0;
            break;
        // Knight not needed, therefore in default
        // Bishop
        case 4:
            if(!Bishop(startrow, startcolumn, destrow, destcolumn, field))
                return 0;
            break;
        // Queen (combination of rook and bishop)
        case 5:
            // vertical or horizontal move
            if((destrow == startrow) || (destcolumn == startcolumn))
            {
                if(!Rook(startrow, startcolumn, destrow, destcolumn, field))
                    return 0;
            }
            // diagonal move
            else
            {
                if (!Bishop(startrow, startcolumn, destrow, destcolumn, field))
                    return 0;
            }
            break;
        // King (for castling)
        case 6:
            if(abs((int)destcolumn - (int)startcolumn) == 2)
            {
                // direction of castling (horizontally)
                if(destcolumn > startcolumn)
                {
                    // checks the area between king and rook
                    if(!Rook(startrow, 7, destrow, 5, field))
                        return 0;
                }
                else
                {
                    if(!Rook(startrow, 0, destrow, 3, field))
                        return 0;
                }
            }
            break;
        // Knight ("no piece" excluded, because checked in CheckMove)
        default:
            break;
    }
    return 1;
}

