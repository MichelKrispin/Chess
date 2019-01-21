#ifndef CHECKCHECKED_H
#define CHECKCHECKED_H

// finds one king and returns the position as row and column
int FindKing(unsigned int *kingrow, unsigned int *kingcolumn, unsigned int field[][8][2]);

// checks whether any king is in check
int CheckChecked(unsigned int field[][8][2]);

#endif
