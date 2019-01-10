// Check whether the move is valid
int CheckMove(char activePLayer, unsigned int startrow, unsigned int startcolumn, unsigned int destrow, unsigned int destcolumn, unsigned int field[][8][2])
{
    if(field[startrow][startcolumn][1] == (unsigned int) activePLayer)
    {
        switch(field[startrow][startcolumn][0])
        {  
            // Pawn
            case 1:
                if(destcolumn == startcolumn)
                {
                    if(activePLayer)
                    {
                        if((destrow == startrow - 1) || ((startrow == 6) && (destrow == 4)))
                            return 1;
                    } 
                    else
                    {
                        if((destrow == startrow + 1) || ((startrow == 1) && (destrow == 3)))
                            return 1;
                    }
                } 
                else if(field[destrow][destcolumn][0] && field[destrow][destcolumn][1] != activePLayer)
                {
                    if((destcolumn - startcolumn == 1) || (startcolumn - destcolumn == 1))
                    {
                        if(activePLayer && (destrow == startrow - 1))
                            return 1;
                        else if(!activePLayer && (destrow == startrow + 1))
                            return 1;
                    }
                }
                break;
            // Rook
            case 2:
                if((destrow == startrow) || (destcolumn == startcolumn))
                    return 1;                
                break;
            // Knight
            case 3:
                if((((destrow - startrow == 1) || (startrow - destrow == 1)) && ((destcolumn - startcolumn == 2) || (startcolumn - destcolumn == 2))) || (((destcolumn - startcolumn == 1) || (startcolumn - destcolumn == 1)) && ((destrow - startrow == 2) || (startrow - destrow == 2))))
                    return 1;
                break;
            // Bishop
            case 4:
                if(destrow - startrow == destcolumn - startcolumn)
                    return 1;
                break;
            // Queen
            case 5:
                if((destrow == startrow) || (destcolumn == startcolumn) || (destrow - startrow == destcolumn - startcolumn))
                    return 1;
                break;
            // King
            case 6:
                if(((destrow - startrow < 2) || (startrow - destrow < 2)) && ((destcolumn - startcolumn < 2) || (startcolumn - destcolumn < 2)))
                    return 1;
                break;
            default: 
                return 0;
                break;
        }
    }
    return 0;
}
