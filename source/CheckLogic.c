#include "CheckLogic.h"
#include "CheckChecked.h"
#include "CheckBlocked.h"
#include "Move.h"

void MoveBack(unsigned int temppiece,
              unsigned int destrow, unsigned int destcolumn,
              unsigned int startrow, unsigned int startcolumn,  
              unsigned int field[][8][2])
{
    Move(destrow, destcolumn, startrow, startcolumn, field);
    field[destrow][destcolumn][0] = temppiece;
    field[destrow][destcolumn][1] = field[destrow][destcolumn][1] ? 0 : 1;
}

// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2])
{
    if(!CheckBlocked(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
        return 0;
    // moves the piece and checks afterwards if your king is still in check (moves the piece back if so)
    unsigned int temppiece = field[startrow][startcolumn][0];
    Move(startrow, startcolumn, destrow, destcolumn, field);
    // white players turn
    if((activePlayer && CheckChecked(field) == 1)
      // black players turn
      || (!activePlayer && CheckChecked(field) == -1))
    {
        MoveBack(temppiece, destrow, destcolumn, startrow, startcolumn, field);
        return 0;
    } 
    MoveBack(temppiece, destrow, destcolumn, startrow, startcolumn, field);
    return 1;
}


