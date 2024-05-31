#include "chess.hpp"

bool over = false;

int botELO;

bool color; // true = white, false = black

board C;

black B;

white W;

int main()
{
    
     
     while (!over)
    {
        startMenu(C, botELO, color, over);

        if (over)
        {
            break;
        }
        play(C, B, W, botELO, over);     
    }

    return 0;
}