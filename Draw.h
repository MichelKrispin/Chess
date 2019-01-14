void TransformRowColumnsToPixel(unsigned int row, unsigned int column,
                                int* xPixel, int* yPixel)
{
    switch (row)
    {
        case 0:
              *yPixel = 35; 
            break;
        case 1:
              *yPixel = 103; 
            break;
        case 2:
              *yPixel = 171; 
            break;
        case 3:
              *yPixel = 240; 
            break;
        case 4:
              *yPixel = 308; 
            break;
        case 5:
              *yPixel = 375; 
            break;
        case 6:
              *yPixel = 442; 
            break;
        case 7:
              *yPixel = 509; 
            break;
    }

    switch (column)
    {
        case 0:
              *xPixel = 35; 
            break;
        case 1:
              *xPixel = 103; 
            break;
        case 2:
              *xPixel = 171; 
            break;
        case 3:
              *xPixel = 237; 
            break;
        case 4:
              *xPixel = 308; 
            break;
        case 5:
              *xPixel = 375; 
            break;
        case 6:
              *xPixel = 442; 
            break;
        case 7:
              *xPixel = 509; 
            break;

    }
}


void TransformPixelToRowColumn(
        int  pixelInputX,
        unsigned int* columnOutput,
        int  pixelInputY,
        unsigned int* rowOutput)
{
    if (pixelInputX > 30 && pixelInputX < 95)
        *columnOutput = 0;
    else if (pixelInputX < 163)
        *columnOutput = 1;
    else if (pixelInputX < 231)
        *columnOutput = 2;
    else if (pixelInputX < 300)
        *columnOutput = 3;
    else if (pixelInputX < 368)
        *columnOutput = 4;
    else if (pixelInputX < 435)
        *columnOutput = 5;
    else if (pixelInputX < 502)
        *columnOutput = 6;
    else if (pixelInputX < 569)
        *columnOutput = 7;
    
    if (pixelInputY > 30 && pixelInputY < 95)
        *rowOutput = 0;
    else if (pixelInputY < 163)
        *rowOutput = 1;
    else if (pixelInputY < 231)
        *rowOutput = 2;
    else if (pixelInputY < 300)
        *rowOutput = 3;
    else if (pixelInputY < 368)
        *rowOutput = 4;
    else if (pixelInputY < 435)
        *rowOutput = 5;
    else if (pixelInputY < 502)
        *rowOutput = 6;
    else if (pixelInputY < 569)
        *rowOutput = 7;
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
            SDL_GetMouseState(&mouse->newMouseX, &mouse->newMouseY);

            // For debug purposes
            //printf("mouseX: %d, mouseY: %d\n",
            //        mouse->newMouseX, mouse->newMouseY);
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
            destinationPosition.w = 60;
            destinationPosition.h = 60;
 
            
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
