#include "CheckLogic.h"
#include "CheckBlocked.h"
#include "Move.h"
#include "CheckChecked.h"
#include "CheckCastling.h"

void CopyField(unsigned int field[][8][2], unsigned int controlfield[][8][2])
{
    for(unsigned int rowcount = 0; rowcount < 8; rowcount++)
    {
        for(unsigned int columnc = 0; columnc < 8; columnc++)
        {
            controlfield[rowcount][columnc][0] = field[rowcount][columnc][0];
            controlfield[rowcount][columnc][1] = field[rowcount][columnc][1];
        }
    }
}

// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2],
               SpecialMoveSet specialMoveSet)
{
    if (field[startrow][startcolumn][1] == (unsigned int)activePlayer)
    {
        if (!CheckBlocked(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
            return 0;
        // for castling 
        if(field[startrow][startcolumn][0] == 6
           && abs((int)destcolumn - (int)startcolumn) == 2)
        {
            // checks if king in check beforehand (not viable then)
            if (CheckChecked(field) || !CheckCastling(activePlayer, destcolumn, field, specialMoveSet))
                return 0;
        }       
        // moves the piece and checks afterwards if your king is in check (moves the piece back if so)
        unsigned int controlfield[8][8][2];
        CopyField(field, controlfield);
        Move(startrow, startcolumn, destrow, destcolumn, controlfield, NULL);
        // white players turn
        if ((activePlayer && CheckChecked(controlfield) == 1)
            // black players turn
            || (!activePlayer && CheckChecked(controlfield) == -1))
        {
            return 0;
        }
    }
    return 1;
}