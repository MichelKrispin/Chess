void Draw(unsigned int field[8][8][2]){

    for(unsigned int rowcount = 0; rowcount < 8; rowcount++){   // Zeilenschleife
        for(unsigned int columnc = 0; columnc < 8; columnc++){  // Spaltenschleife
            if((rowcount + columnc) % 2 == 0)                   // Hintergrund (s/w)
                BG_WHITE;            
            else
                BG_BLACK;
            switch(field[rowcount][columnc][0]){                // Figuren (Buchst.)
                case 1: printf(" P ");
                default: printf("   ");
            }
        }
        printf("\n");                                           // Zeilenumbruch
    }
} 
