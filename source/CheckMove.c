#include "CheckMove.h"
#include <stdlib.h>
#include <stdio.h>

// Check whether the move is valid
int CheckMove(char activePlayer, 
              unsigned int startrow, unsigned int startcolumn, 
              unsigned int destrow, unsigned int destcolumn, 
              unsigned int field[][8][2])
{
    if(field[startrow][startcolumn][1] == (unsigned int) activePlayer
      && (destrow != startrow || destcolumn != startcolumn))
    {
        switch(field[startrow][startcolumn][0])
        {  
            // Pawn
            case 1:
                // standart move
                if(destcolumn == startcolumn)
                {
                    // move direction decided by activePlayer
                    if(activePlayer)
                    {
                        if((destrow == startrow - 1) || 
                          ((startrow == 6) && (destrow == 4)))
                            return 1;
                    } 
                    else
                    {
                        if((destrow == startrow + 1) || 
                          ((startrow == 1) && (destrow == 3)))
                            return 1;
                    }
                }
                // taking a piece (diagonal)
                else if(field[destrow][destcolumn][0] && 
                        field[destrow][destcolumn][1] != (unsigned int)activePlayer)
                {
                    if((destcolumn - startcolumn == 1) || 
                      (startcolumn - destcolumn == 1))
                    {
                        // move direction
                        if(activePlayer && (destrow == startrow - 1))
                            return 1;
                        else if(!activePlayer && (destrow == startrow + 1))
                            return 1;
                    }
                }
                break;
            // Rook
            case 2:
                if((destrow == startrow) || (destcolumn == startcolumn))
                    return 1;                
                break;
            // Knight
            case 3:
                // move : 1 field vertically or horizontally and then 2 the other of the two
                if(((abs((int)destrow - (int)startrow) == 1) && (abs((int)destcolumn - (int)startcolumn) == 2)) || 
                  ((abs((int)destcolumn - (int)startcolumn) == 1) && (abs((int)destrow - (int)startrow) == 2)))
                    return 1;
                break;
            // Bishop
            case 4:
                // diagonal := x - difference = y - diff.
                if(abs((int)destrow - (int)startrow) == abs((int)destcolumn - (int)startcolumn))
                    return 1;
                break;
            // Queen
            case 5:
                // combination of rook and bishop
                if((destrow == startrow) || 
                  (destcolumn == startcolumn) || 
                  abs((int)destrow - (int)startrow) == abs((int)destcolumn - (int)startcolumn))
                    return 1;
                break;
            // King
            case 6:
                // move : 1 in any direction
                if((abs((int)destrow - (int)startrow) < 2) && 
                  (abs((int)destcolumn - (int)startcolumn) < 2))
                    return 1;
                break;
            // no selected
            default: 
                return 0;
                break;
        }
    }
    return 0;
}

