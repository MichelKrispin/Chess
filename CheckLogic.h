#include "CheckBlocked.h"

// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2])
{
    if(!CheckBlocked(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
        return 0;
    return 1;
}
