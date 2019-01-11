void TransformRowColumnsToPixel(unsigned int row, unsigned int column,
                                int* xPixel, int* yPixel)
{
    // Calculate row to y data
    row += 1;
    *yPixel = row * 40 + 30;
   
    // Calculate column to x data
    column += 1;
    *xPixel = column * 40 + 30;

}



int Draw(unsigned int field[8][8][2], Window* sdlWindow, Figure* figures)
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
                        }
                        break;
                     }                   

                default: 
                    continue;
                    
            }
        }
    }
    

     
    SDL_RenderPresent(sdlWindow->renderer);
    
    SDL_Delay(16);
 

    return 1;
} 
