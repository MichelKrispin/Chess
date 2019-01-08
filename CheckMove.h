// Check whether the move is valid
int CheckMove(char activePLayer, unsigned int startrow, unsigned int startcolumn, unsigned int destrow, unsigned int destcolumn, unsigned int field[][8][2])
{
    if(field[startrow][startcolumn][1] == (unsigned int) activePLayer)
    {
        switch(field[startrow][startcolumn][0])
        {
            case 1:
                if(destcolumn == startcolumn)
                {
                    if(activePLayer)
                    {
                        if((destrow == startrow - 1) || ((startrow == 6) && (destrow == startrow - 2)))
                            return 1;
                    } 
                    else
                    {
                        if((destrow == startrow + 1) || ((startrow == 1) && (destrow == startrow + 2)))
                            return 1;
                    }
                }
                break;
            case 2:
                if((destrow == startrow) || (destcolumn == startcolumn))
                    return 1;                
                break;
            case 3:
                //if(())
                break;
            case 4:
                if(destrow - startrow == destcolumn - startcolumn)
                    return 1;
                break;
            case 5:
                break;
            case 6:
                if((destrow - startrow == 1))
                break;
        }
    }
}
