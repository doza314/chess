#include "chess.hpp"

bool over = false;

bool color; // true = white, false = black

board C;

player P;

bot BOT;

int main()
{
    
     
     while (!over)
    {
        startMenu(C, P, BOT, color, over);
        if (over)
        {
            break;
        }
        play(C, P, BOT, over);     
    }

    return 0;
}