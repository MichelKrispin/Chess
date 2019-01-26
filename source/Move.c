#include "Move.h"

void Move(unsigned int startrow, unsigned int startcolumn, 
          unsigned int destrow, unsigned int destcolumn, 
          unsigned int field[][8][2],
          SpecialMoveSet *specialMoveSet)
{
    if (field[startrow][startcolumn][0] != 0)
    {
        // sets already moved or taken pieces to 1 (for castling)
        // black left Rook
        if((startrow == 0 && startcolumn == 0)
           || (destrow == 0 && destcolumn == 0))
            specialMoveSet->bLeftRook = 1;
        // black right
        else if((startrow == 0 && startcolumn == 7)
                || (destrow == 0 && destcolumn == 7))
            specialMoveSet->bRightRook = 1;
        // white left
        else if((startrow == 7 && startcolumn == 0)
                || (destrow == 7 && destcolumn == 0))
            specialMoveSet->wLeftRook = 1;
        // white right
        else if((startrow == 7 && startcolumn == 7)
                || (destrow == 7 && destcolumn == 7))
            specialMoveSet->wRightRook = 1;
        // black King
        else if(startrow == 0 && startcolumn == 4)
            specialMoveSet->blackKing = 1;
        // white King
        else if(startrow == 7 && startcolumn == 4)
            specialMoveSet->whiteKing = 1;
        // sets the column to which a pawn can use enPassente to move to
        if(field[startrow][startcolumn][0] == 1
           && abs((int)destrow - (int)startrow) == 2)
        {
            // if clauses hinder unexpected behaviour (outside of field)
            if(destcolumn > 0)
            {
                if(destcolumn < 7)
                {
                    if(field[destrow][destcolumn + 1][0] == 1 || field[destrow][destcolumn - 1][0] == 1)
                        specialMoveSet->enPassenteColumn = startcolumn;
                }
                else
                {
                    if(field[destrow][destcolumn - 1][0] == 1)
                        specialMoveSet->enPassenteColumn = startcolumn;
                }
            }
            else
            {
                if(field[destrow][destcolumn + 1][0] == 1)
                    specialMoveSet->enPassenteColumn = startcolumn;
            }
        }
        // if the pawn didnt set enPassente up changes enPassenteColumn to outside of field
        else
        {
            specialMoveSet->enPassenteColumn = 9;
        }        
        // actual movement part
        field[destrow][destcolumn][0] = field[startrow][startcolumn][0];
        field[destrow][destcolumn][1] = field[startrow][startcolumn][1];
        field[startrow][startcolumn][0] = 0;
        specialMoveSet->enPassente = 0;
    }
}

