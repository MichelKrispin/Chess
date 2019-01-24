#include "CheckCastling.h"

int CheckCastling(char activePlayer,
                  unsigned int destcolumn,
                  unsigned int field[][8][2],
                  SpecialMoveSet specialMoveSet)
{
    if(activePlayer && !specialMoveSet.whiteKing)
    {
        if(destcolumn > 4 && !specialMoveSet.wRightRook)
            return 1;
        else if(!specialMoveSet.wLeftRook)
            return 1;
    }
    else if(!specialMoveSet.blackKing)
    {
        if(destcolumn > 4 && !specialMoveSet.bRightRook)
            return 1;
        else if(!specialMoveSet.bLeftRook)
            return 1;
    }
    return 0;    
}