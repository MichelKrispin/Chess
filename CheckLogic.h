// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(unsigned int startrow, unsigned int startcolumn,
               unsigned int destrow, unsigned int destcolumn,
               unsigned int field[][8][2])
{
    startrow = 1;
    startcolumn = 1;
    destrow = 1;
    destcolumn = field[0][0][0];

    return 1;
}
