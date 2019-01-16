#include "SDL.h"

Figure CreateFigureAt(char type[2], const char* imagePath, SDL_Renderer* renderer)
{
    Figure figure;
    // Create figure
    figure.image = SDL_LoadBMP(imagePath);
    figure.texture = SDL_CreateTextureFromSurface(renderer, figure.image);

    figure.imageInfo.x = 0;
    figure.imageInfo.y = 0;
    figure.imageInfo.w = 30;
    figure.imageInfo.h = 45;

    figure.type[0] = type[0];
    figure.type[1] = type[1];

    return figure;
}

void RenderFigures(int count, Figure* figures, SDL_Renderer* renderer)
{
    for (int i = 0; i < count; i++)
    {
        SDL_RenderCopy(renderer, figures[i].texture, NULL, &figures[i].imageInfo);
    }
}

// Initializes all figures
void InitializeFigures(Figure* figures, Window* sdlWindow)
{
    // Initialize figures
    // Initialize white pawns
    for (int i = 0; i < 8; i++)
        figures[i] = CreateFigureAt("wp", "media/W_Pawn.bmp", sdlWindow->renderer);

    // Initialize white pawns
    figures[8] = CreateFigureAt("wr", "media/W_Rook.bmp", sdlWindow->renderer);
    figures[9] = CreateFigureAt("wr", "media/W_Rook.bmp", sdlWindow->renderer);

    // Initialize white knights
    figures[10] = CreateFigureAt("wn", "media/W_Knight.bmp", sdlWindow->renderer);
    figures[11] = CreateFigureAt("wn", "media/W_Knight.bmp", sdlWindow->renderer);

    // Initialize white bishops
    figures[12] = CreateFigureAt("wb", "media/W_Bishop.bmp", sdlWindow->renderer);
    figures[13] = CreateFigureAt("wb", "media/W_Bishop.bmp", sdlWindow->renderer);

    // Initialize white king and queen
    figures[14] = CreateFigureAt("wq", "media/W_Queen.bmp", sdlWindow->renderer);
    figures[15] = CreateFigureAt("wk", "media/W_King.bmp", sdlWindow->renderer);

    // Initialize black pawns
    for (int i = 16; i < 24; i++)
        figures[i] = CreateFigureAt("bp", "media/B_Pawn.bmp", sdlWindow->renderer);

    // Initialize black tower
    figures[24] = CreateFigureAt("br", "media/B_Rook.bmp", sdlWindow->renderer);
    figures[25] = CreateFigureAt("br", "media/B_Rook.bmp", sdlWindow->renderer);

    // Initialize black knights
    figures[26] = CreateFigureAt("bn", "media/B_Knight.bmp", sdlWindow->renderer);
    figures[27] = CreateFigureAt("bn", "media/B_Knight.bmp", sdlWindow->renderer);

    // Initialize black bishops
    figures[28] = CreateFigureAt("bb", "media/B_Bishop.bmp", sdlWindow->renderer);
    figures[29] = CreateFigureAt("bb", "media/B_Bishop.bmp", sdlWindow->renderer);

    // Initialize black queen and king
    figures[30] = CreateFigureAt("bq", "media/B_Queen.bmp", sdlWindow->renderer);
    figures[31] = CreateFigureAt("bk", "media/B_King.bmp", sdlWindow->renderer);
}

void ClearFigureMemory(int count, Figure* figures)
{
    for (int i = 0; i < count; i++)
    {
        SDL_DestroyTexture(figures[i].texture);
        SDL_FreeSurface(figures[i].image);
    }   
}
