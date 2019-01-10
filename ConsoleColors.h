#ifndef CONSOLECOLORS_H
#define CONSOLECOLORS_H


// Colors which should be set in before each printf command
#define COLOR_RESET  printf("\x1B[0m")
#define COLOR_RED    printf("\x1B[31m")
#define COLOR_GREEN  printf("\x1B[32m")
#define COLOR_YELLOW printf("\x1B[33m")
#define COLOR_BLUE   printf("\x1b[34m")
#define COLOR_CYAN   printf("\x1B[36m")
#define COLOR_WHITE  printf("\x1b[37m")

#define BG_BLACK     printf("\x1b[40m")
#define BG_RED       printf("\x1b[41m")
#define BG_WHITE     printf("\x1b[47m")

#endif // CONSOLECOLORS_H
