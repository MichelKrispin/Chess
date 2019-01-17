#ifndef CHECKLOGIC_H
#define CHECKLOGIC_H

void MoveBack(unsigned int temppiece,
              unsigned int destrow, unsigned int destcolumn,
              unsigned int startrow, unsigned int startcolumn,  
              unsigned int field[][8][2]);;

// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2]);

#endif
