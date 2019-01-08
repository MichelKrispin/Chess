int Move(unsigned int row, unsigned int column, unsigned int field[][8][2])
{
    field[destrow][destcolumn][0] = field[startrow][startcolumn][0];
    field[destrow][destcolumn][1] = field[startrow][startcolumn][1];
    field[startrow][startcolumn][0] = 0;
}
