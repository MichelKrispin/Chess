void Draw(unsigned int field[8][8][2]){

    // Zeilenschleife
    for(unsigned int rowcount = 0; rowcount < 8; rowcount++)
    {   
        // Spaltenschleife
        for(unsigned int columnc = 0; columnc < 8; columnc++)
        {  
            // TODO: Option to change colors 
            if (field[rowcount][columnc][1])
                COLOR_RESET;
            else
                COLOR_BLUE;
            
            if((rowcount + columnc) % 2 == 0)                   // Hintergrund (s/w)
                BG_WHITE;            
            else
                BG_BLACK;
            
            switch(field[rowcount][columnc][0])
            {                // Figuren (Buchst.)
                case 1: 
                    printf(" P ");
                    break;
                case 2: 
                    printf(" T ");
                    break;
                case 3: 
                    printf(" N ");
                    break;
                case 4: 
                    printf(" B ");
                    break;
                case 5: 
                    printf(" Q ");
                    break;
                case 6: 
                    printf(" K ");
                    break;

                default: 
                    printf("   ");
            }
        }
        printf("\n");                                           // Zeilenumbruch
    }
} 
