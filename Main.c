#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "ConsoleColors.h"
#include "Draw.h"
#include "Initialize.h"

int main()
{
    unsigned int field[8][8][2];                          // Array Initialisieren
    memset(field, 0, sizeof(field)); // Set all elements to 0

    // Initialize field array with data
    InitializeField(field);
   
    Draw(field);                            // Draw the field

    return 0;
}
