void Draw()
{
    COLOR_RESET;
    setlocale(LC_ALL, "");
    BG_WHITE;
    printf("%lc", (wint_t) 9812);
    BG_BLACK;
    printf("%lc\n", (wint_t) 9812);
} 
