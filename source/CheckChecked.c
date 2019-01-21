#include "CheckChecked.h"
#include "CheckMove.h"
#include "CheckBlocked.h"

// finds one king and returns the position as row and column
int FindKing(unsigned int *kingrow, unsigned int *kingcolumn, unsigned int field[][8][2])
{
    // loop for every fieldposition
    for(; *kingrow < 8; (*kingrow)++)
    {
        for(; *kingcolumn < 8; (*kingcolumn)++)
        {
            if(field[*kingrow][*kingcolumn][0] == 6)
            {
                return 1;
            }
        // for second found king
        }
        *kingcolumn = 0;
    }
}

// checks whether any king is in check
int CheckChecked(unsigned int field[][8][2])
{
    // kingpositions
    unsigned int kingrow = 0;
    unsigned int kingcolumn = 0;
    // two kings, therefore twice
    for(char twice = 0; twice < 2; twice++)
    {
        FindKing(&kingrow, &kingcolumn, field);
        // checks every fieldpos. for a piece that could take the kingpiece
        for(unsigned int startrow = 0; startrow < 8; startrow++)
        {
            for(unsigned int startcolumn = 0; startcolumn < 8; startcolumn++)
            {
                if(CheckMove(field[startrow][startcolumn][1], startrow, startcolumn, kingrow, kingcolumn, field)
                  && CheckBlocked(field[startrow][startcolumn][1], startrow, startcolumn, kingrow, kingcolumn, field))
                {
                    // returns the color of the player that's in check (-1 = black, 1 = white)
                    return field[startrow][startcolumn][1] ? -1 : 1;
                }
            }
        }
        // for second king, so that FindKing can be executed again
        if(kingcolumn == 7)
        {
            kingrow++;
            kingcolumn = 0;
        }
        else
            kingcolumn++;
    }
    // if no king is in check
    return 0;
}
