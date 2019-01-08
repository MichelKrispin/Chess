#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "ConsoleColors.h"
#include "Draw.h"
#include "Initialize.h"

int main()
{
    // Initialize array to 0
    unsigned int field[8][8][2];                          
    memset(field, 0, sizeof(field)); 

    // Initialize field array with data
    InitializeField(field);
   
    Draw(field);                            // Draw the field

    return 0;
}
