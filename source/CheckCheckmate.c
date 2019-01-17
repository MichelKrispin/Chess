#include "CheckCheckmate.h"
#include "CheckMove.h"
#include "CheckChecked.h"
#include "CheckLogic.h"

// Check whether any King is now in Checkmate
int CheckCheckmate(unsigned int field[][8][2])
{
    for(unsigned int startrow = 0; startrow < 8; startrow++)
    {
        for(unsigned int startcolumn = 0; startcolumn < 8; startcolumn++)
        {
            for(unsigned int destrow = 0; destrow < 8; destrow++)
            {
                for(unsigned int destcolumn = 0; destcolumn < 8; destcolumn++)
                {
                    if(CheckMove(field[startrow][startcolumn][1], startrow, startcolumn, destrow, destcolumn, field) 
                      && CheckLogic(field[startrow][startcolumn][1], startrow, startcolumn, destrow, destcolumn, field))
                        return 0;
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

