#ifndef MOVE_H
#define MOVE_H

#include "StructDefinitions.h"

// Change the position of the given figure
void Move(unsigned int startrow, unsigned int startcolumn, 
          unsigned int destrow, unsigned int destcolumn, 
          unsigned int field[][8][2],
          SpecialMoveSet *specialMoveSet);

#endif
