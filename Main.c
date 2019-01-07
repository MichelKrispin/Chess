#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "ConsoleColors.h"
#include "Draw.h"

int main()
{
    unsigned int field[8][8][2] = {0};                          // Array Initialisieren
    for(unsigned int rowcount = 0; rowcount < 8; rowcount++){
        for(unsigned int columnc = 0; columnc < 8; columnc++){
            if((rowcount == 1) || (rowcount == 6))              // Bauern
                field[rowcount][columnc][0] = 1;
            else if(rowcount == 0){                             // Restfiguren
                if(columnc < 4)
                    field[rowcount][columnc][0] = columnc + 2;
                else if()
                else
                    field[rowcount][columnc][0] = 9 - columnc;
            }
            if(rowcount > 5)
                field[rowcount][columnc][1] = 1;                // weiße Farbe
        }
    }
    BG_WHITE;
    COLOR_RED;
    printf("Hello World!\n");
    COLOR_YELLOW;
    BG_BLACK;
    printf("Hello World!\n");
    Draw(field);                            // Funktion

    return 0;
}
