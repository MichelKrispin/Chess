#include "ShowMessageBox.h"
#include "SDL.h"
#include <string.h>

// Returns 0 for play again
// Return 1 for exit
int ShowMessageBox(char* title, char* message)
{
    const SDL_MessageBoxButtonData buttons[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Play again" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Exit" }
    };
    const SDL_MessageBoxColorScheme colorScheme = {
        { 
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };

    // Set outputTitle
    char outputTitle[50];
    strcpy(outputTitle, title);
    // Set outputMessage
    char outputMessage[100];
    strcpy(outputMessage, message);

    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        outputTitle, /* .title */
        outputMessage, /* .message */
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
    }
    return buttonid;
}



// Returns 0 for Queen
// Returns 1 for Rook
// Returns 2 for Bishop
// Returns 3 for Knight
int ShowSwapMessageBox()
{
    const SDL_MessageBoxButtonData buttons[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 5, "Queen" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "Rook" },
        { 0                                      , 4, "Bishop" },
        { 0                                      , 3, "Knight" }
    };
    const SDL_MessageBoxColorScheme colorScheme = {
        { 
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };

    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        "Swap pawn", /* .title */
        "Which figure do you want?", /* .message */
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
    }
    return buttonid;
}
