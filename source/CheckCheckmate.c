#include "CheckCheckmate.h"
#include "CheckMove.h"
#include "CheckLogic.h"
#include "CheckChecked.h"
#include <stdio.h>

// Check whether any King is now in Checkmate
int CheckCheckmate(char activePlayer, unsigned int field[][8][2], SpecialMoveSet specialMoveSet)
{
    activePlayer = activePlayer ? 0 : 1;
    for(unsigned int startrow = 0; startrow < 8; startrow++)
    {
        for(unsigned int startcolumn = 0; startcolumn < 8; startcolumn++)
        {
            for(unsigned int destrow = 0; destrow < 8; destrow++)
            {
                for(unsigned int destcolumn = 0; destcolumn < 8; destcolumn++)
                {
                    if(CheckMove(activePlayer, startrow, startcolumn, destrow, destcolumn, field)
                      && CheckLogic(activePlayer, startrow, startcolumn, destrow, destcolumn, field, &specialMoveSet))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    // returns Checkmate (1) or Stalemate (-1)
    if(CheckChecked(field))
        return 1;
    else
        return -1;
}
