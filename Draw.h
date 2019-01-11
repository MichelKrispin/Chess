void TransformRowColumnsToPixel(unsigned int row, unsigned int column,
                                int* xPixel, int* yPixel)
{
    /* TODO: Calculate simple
    // Calculate row to y data
    row += 1;
    *yPixel = row * 40;
   
    // Calculate column to x data
    column += 1;
    *xPixel = column * 40 + 20;
    */

    row += 1;
    switch (row)
    {
        case 1:
              *yPixel = 45; 
            break;
        case 2:
              *yPixel = 115; 
            break;
        case 3:
              *yPixel = 185; 
            break;
        case 4:
              *yPixel = 250; 
            break;
        case 5:
              *yPixel = 320; 
            break;
        case 6:
              *yPixel = 385; 
            break;
        case 7:
              *yPixel = 450; 
            break;
        case 8:
              *yPixel = 520; 
            break;

    }

    column += 1;
    switch (column)
    {
        case 1:
              *xPixel = 50; 
            break;
        case 2:
              *xPixel = 115; 
            break;
        case 3:
              *xPixel = 185; 
            break;
        case 4:
              *xPixel = 245; 
            break;
        case 5:
              *xPixel = 320; 
            break;
        case 6:
              *xPixel = 390; 
            break;
        case 7:
              *xPixel = 455; 
            break;
        case 8:
              *xPixel = 525; 
            break;

    }
}


void TransformPixelToRowColumn(
        int  pixelInputX,
        unsigned int* rowOutput,
        int  pixelInputY,
        unsigned int* columnOutput)
{
    if (pixelInputY < 45)
        *columnOutput = 1;
    else if (pixelInputY < 115)
        *columnOutput = 2;
    else if (pixelInputY < 185)
        *columnOutput = 3;
    else if (pixelInputY < 250)
        *columnOutput = 4;
    else if (pixelInputY < 320)
        *columnOutput = 5;
    else if (pixelInputY < 385)
        *columnOutput = 6;
    else if (pixelInputY < 450)
        *columnOutput = 7;
    else if (pixelInputY < 520)
        *columnOutput = 8;
    
    if (pixelInputX < 50)
        *rowOutput = 1;
    else if (pixelInputX < 115)
        *rowOutput = 2;
    else if (pixelInputX < 185)
        *rowOutput = 3;
    else if (pixelInputX < 245)
        *rowOutput = 4;
    else if (pixelInputX < 320)
        *rowOutput = 5;
    else if (pixelInputX < 390)
        *rowOutput = 6;
    else if (pixelInputX < 455)
        *rowOutput = 7;
    else if (pixelInputX < 525)
        *rowOutput = 8;

}

int Draw(unsigned int field[8][8][2],
         Window* sdlWindow,
         Figure* figures,
         MousePosition* mouse)
{
    SDL_Event event;

    // Poll events
    SDL_PollEvent(&event);
    // Handle events
    switch(event.type)
    {
        case SDL_QUIT:
            return 0;
        break;
        case SDL_MOUSEBUTTONDOWN:
            mouse->newMouseX = event.motion.x;
            mouse->newMouseY = event.motion.y;
        break;
    }

    // Render background
    SDL_RenderCopy(sdlWindow->renderer, sdlWindow->background, NULL, NULL);

    // Set all isSet flags of all figures to 0
    for (int i = 0; i < 32; i++)
    {
        figures[i].isSet = 0;
    }
   
    
    // Zeilenschleife
    for(unsigned int rowcount = 0; rowcount < 8; rowcount++)
    {   
        // Spaltenschleife
        for(unsigned int columnc = 0; columnc < 8; columnc++)
        { 
            int xPixel = 0, yPixel = 0;
            TransformRowColumnsToPixel(rowcount, columnc, &xPixel, &yPixel);
            SDL_Rect destinationPosition;
            destinationPosition.x = xPixel;
            destinationPosition.y = yPixel;
            destinationPosition.w = 30;
            destinationPosition.h = 45;
 
            
            switch(field[rowcount][columnc][0])
            {                // Figuren (Buchst.)

                // Pawns
                case 1: 
                    {
                        int player = 16;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        for (int i = player; i < player + 8; i++)
                        {
                            if (figures[i].isSet == 0)
                            {
                                SDL_RenderCopy(sdlWindow->renderer, figures[i].texture, NULL, &destinationPosition);
                                figures[i].isSet = 1;
                                break;
                            }
                        }
                        break;
                    }

                // Rooks (Tower)
                case 2: 
                    {
                        int player = 24;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        for (int i = player; i < player + 2; i++)
                        {
                            if (figures[i].isSet == 0)
                            {
                                SDL_RenderCopy(sdlWindow->renderer, figures[i].texture, NULL, &destinationPosition);
                                figures[i].isSet = 1;
                                break;
                            }
                        }
                        break;
                    }

                // Knights
                case 3: 
                    {
                        int player = 26;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        for (int i = player; i < player + 2; i++)
                        {
                            if (figures[i].isSet == 0)
                            {
                                SDL_RenderCopy(sdlWindow->renderer, figures[i].texture, NULL, &destinationPosition);
                                figures[i].isSet = 1;
                                break;
                            }
                        }
                        break;
                     }

                // Bishops
                case 4: 
                     {
                        int player = 28;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        for (int i = player; i < player + 2; i++)
                        {
                            if (figures[i].isSet == 0)
                            {
                                SDL_RenderCopy(sdlWindow->renderer, figures[player].texture, NULL, &destinationPosition);
                                figures[i].isSet = 1;
                                break;
                            }
                        }
                        break;
                     }                   

                // Queens
                case 5: 
                    {
                        int player = 30;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        if (figures[player].isSet == 0)
                        {
                            SDL_RenderCopy(sdlWindow->renderer, figures[player].texture, NULL, &destinationPosition);
                            figures[player].isSet = 1;
                            break;
                        }
                        break;
                     }                   

                // Kings
                case 6: 
                    {
                        int player = 31;
                        if (field[rowcount][columnc][1] == 1)
                            player -= 16;

                        if (figures[player].isSet == 0)
                        {
                            SDL_RenderCopy(sdlWindow->renderer, figures[player].texture, NULL, &destinationPosition);
                            figures[player].isSet = 1;
                            break;
                        }
                        break;
                     }                   

                default: 
                    continue;
                    
            }
        }
    }
    

     
    SDL_RenderPresent(sdlWindow->renderer);
    
    return 1;
} 
