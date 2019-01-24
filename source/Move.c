#include "Move.h"

void Move(unsigned int startrow, unsigned int startcolumn, 
          unsigned int destrow, unsigned int destcolumn, 
          unsigned int field[][8][2],
          SpecialMoveSet *specialMoveSet)
{
    if (field[startrow][startcolumn][0] != 0)
    {
        field[destrow][destcolumn][0] = field[startrow][startcolumn][0];
        field[destrow][destcolumn][1] = field[startrow][startcolumn][1];
        field[startrow][startcolumn][0] = 0;
        // black left Rook
        if(startrow == 0 && startcolumn == 0)
            specialMoveSet->bLeftRook = 1;
        // black right
        else if(startrow == 0 && startcolumn == 7)
            specialMoveSet->bRightRook = 1;
        // white left
        else if(startrow == 7 && startcolumn == 0)
            specialMoveSet->wLeftRook = 1;
        // white right
        else if(startrow == 7 && startcolumn == 7)
            specialMoveSet->wRightRook = 1;
        // black King
        else if(startrow == 0 && startcolumn == 4)
            specialMoveSet->blackKing = 1;
        // white King
        else if(startrow == 7 && startcolumn == 4)
            specialMoveSet->whiteKing = 1;
    }
}

