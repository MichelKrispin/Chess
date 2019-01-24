#ifndef CHECKCASTLING_H
#define CHECKCASTLING_H

#include "StructDefinitions.h"

int CheckCastling(char activePlayer,
                  unsigned int destcolumn,
                  unsigned int field[][8][2],
                  SpecialMoveSet specialMoveSet);

#endif