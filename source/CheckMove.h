#ifndef CHECKMOVE_H
#define CHECKMOVE_H

// Check whether the move is valid
int CheckMove(char activePLayer, 
              unsigned int startrow, unsigned int startcolumn, 
              unsigned int destrow, unsigned int destcolumn, 
              unsigned int field[][8][2]);

#endif
