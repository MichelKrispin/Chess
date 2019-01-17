#ifndef CHECKBLOCKED_H
#define CHECKBLOCKED_H


// used for rook and queen
int Rook(unsigned int startrow, unsigned int startcolumn, 
         unsigned int destrow, unsigned int destcolumn, 
         unsigned int field[][8][2]);

// used for bishop and queen
int Bishop(unsigned int startrow, unsigned int startcolumn, 
           unsigned int destrow, unsigned int destcolumn, 
           unsigned int field[][8][2]);

// checks for a piece in the way of the players move
int CheckBlocked(char activePlayer, 
                 unsigned int startrow, unsigned int startcolumn, 
                 unsigned int destrow, unsigned int destcolumn, 
                 unsigned int field[][8][2]);

#endif
