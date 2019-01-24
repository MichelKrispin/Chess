#ifndef CHECKLOGIC_H
#define CHECKLOGIC_H

#include "StructDefinitions.h"

void CopyField(unsigned int field[][8][2], unsigned int controlfield[][8][2]);

// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2],
               SpecialMoveSet specialMoveSet);

#endif