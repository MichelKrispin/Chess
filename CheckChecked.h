// finds one king and returns the position as row and column
void FindKing(unsigned int *kingrow, unsigned int *kingcolumn, unsigned int field[][8][2])
{
    // loop for every fieldposition
    for(; *kingrow < 8; (*kingrow)++)
    {
        for(; *kingcolumn < 8; (*kingcolumn)++)
        {
            if(field[*kingrow][*kingcolumn][0] == 6)
            {
                break;
            }
            // for second found king
            *kingcolumn = 0;
        }
        break;
    }
}

// checks whether any king is in check
int CheckChecked(char activePlayer, unsigned int field[][8][2])
{
    // kingpositions
    unsigned int kingrow = 0;
    unsigned int kingcolumn = 0;
    // two kings, therefore twice
    for(char twice = 0; !twice; twice++)
    {
        FindKing(&kingrow, &kingcolumn, field);
        // for second king, so that FindKing can be executed again
        if(kingcolumn == 7)
        {
            kingrow++;
            kingcolumn = 0;
        }
        // checks every fieldpos. for a piece that could take the kingpiece
        for(unsigned int startrow = 0; startrow < 8; startrow++)
        {
            for(unsigned int startcolumn = 0; startcolumn < 8; startcolumn++)
            {
                if(CheckMove(activePlayer, startrow, startcolumn, kingrow, kingcolumn, field)
                  && CheckLogic(activePlayer, startrow, startcolumn, kingrow, kingcolumn, field))
                {
                    // returns the color of the piece (1 = white, -1 black)
                    return field[startrow][startcolumn][1] ? 1 : -1;
                }
            }
        }
    }
    // if no king is in check
    return 0;
}