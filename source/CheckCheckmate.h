#ifndef CHECKCHECKMATE_H
#define CHECKCHECKMATE_H

#include "StructDefinitions.h"

// Check whether any King is now in Checkmate
int CheckCheckmate(char activePlayer,
                   unsigned int field[][8][2],
                   SpecialMoveSet specialMoveSet);

#endif
