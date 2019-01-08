// Change the position of the given figure
int Move(unsigned int startrow, unsigned int startcolumn,
         unsigned int destrow, unsigned int destcolumn,
         unsigned int field[][8][2])
{
    field[destrow][destcolumn][0] = field[startrow][startcolumn][0];
    field[destrow][destcolumn][1] = field[startrow][startcolumn][1];
    field[startrow][startcolumn][0] = 0;
}
