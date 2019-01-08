// Gets the input and saves it into the given reference values
int GetInput(unsigned int* startrow, unsigned int* startcolumn,
             unsigned int* destrow, unsigned int* destcolumn)
{
    COLOR_RESET;
    printf("Input starting position as row and column\n\
and then the destination position as row and column\n");

    // Get four input values 
    scanf("%u %u %u %u",
           &(*startrow), &(*startcolumn), &(*destrow), &(*destcolumn));

    // If all 9 give up
    if (*startrow    == 9 && *destrow    == 9 
     && *startcolumn == 9 && *destcolumn == 9)
        return 3;

    // If all 0 exit
    if (*startrow    == 0 && *destrow    == 0 
     && *startcolumn == 0 && *destcolumn == 0)
        return 2;


    // Check whether input is valid
    if (*startrow    > 10 || *destrow    > 10
     || *startcolumn > 10 || *destcolumn > 10
     || *startrow    == 0 || *destrow    == 0 
     || *startcolumn == 0 || *destcolumn == 0)
        return 0;

    // Destination can't be the same as the starting position   
    if (*startrow    == *destrow
     && *startcolumn == *destcolumn)
        return 0;

    // Manipulate columns to be chess correct
    // And start counting at 0
    *startrow       = 8 - *startrow;
    *destrow        = 8 - *destrow;
    *startcolumn   -= 1;
    *destcolumn    -= 1;

    // Return true
    return 1;
}
