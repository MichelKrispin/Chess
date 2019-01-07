#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "ConsoleColors.h"
#include "Draw.h"

int main()
{

    COLOR_RED;
    printf("Hello World!\n");
    COLOR_YELLOW;
    printf("Hello World!\n");


    COLOR_RESET;
    setlocale(LC_ALL, "");
    BG_WHITE;
    printf("%lc", (wint_t) 9812);
    BG_BLACK;
    printf("%lc\n", (wint_t) 9812);
    return 0;
}
