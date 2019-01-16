// Check whether the move is valid
// i.e. the move doesn't put own King into Check
int CheckLogic(char activePlayer, 
               unsigned int startrow, unsigned int startcolumn, 
               unsigned int destrow, unsigned int destcolumn, 
               unsigned int field[][8][2])
{
    if(!CheckBlocked(activePlayer, startrow, startcolumn, destrow, destcolumn, field))
        return 0;
    // moves the piece and checks afterwards if your king is still in check (moves the piece back if so)
    Move(startrow, startcolumn, destrow, destcolumn, field);
    // white players turn
    if((activePlayer && CheckChecked(field) == 1)
      // black players turn
      || (!activePlayer && CheckChecked(field) == -1))
    {
        Move(destrow, destcolumn, startrow, startcolumn, field);
        return 0;
    } 
    Move(destrow, destcolumn, startrow, startcolumn, field);
    return 1;
}

