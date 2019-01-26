#ifndef INITIALIZEDEBUG_H
#define INITIALIZEDEBUG_H

#include "StructDefinitions.h"

void SetSpecialMoveSetZero(SpecialMoveSet *specialMoveSet);
void InitializeDebugField(unsigned int field[][8][2], SpecialMoveSet *specialMoveSet);
void InitializeDebugField2(unsigned int field[][8][2], SpecialMoveSet *specialMoveSet);

#endif