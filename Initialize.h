void InitializeField(unsigned int field[][8][2])
{
    // Set all third array elements to be either 0 as empty
    // Or numbers for different figure
    // Pawn  = 1
    // Tower = 2
    // Knight = 3
    // Bishop = 4
    // Queen = 5
    // King = 6

    for(unsigned int rowcount = 0; rowcount < 8; rowcount++)
    {
        for(unsigned int columnc = 0; columnc < 8; columnc++)
        {
            if((rowcount == 1) || (rowcount == 6))              // Bauern
                field[rowcount][columnc][0] = 1;
            else if(rowcount == 0)
            {                             // Restfiguren
                if(columnc < 4)
                    field[rowcount][columnc][0] = columnc + 2;
                //else if()
                else
                    field[rowcount][columnc][0] = 9 - columnc;
            }
            if(rowcount > 5)
                field[rowcount][columnc][1] = 1;                // weiße Farbe
        }
    }
 
}
