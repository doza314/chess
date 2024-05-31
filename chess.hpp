#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

class board
{
    private:
    int boardSize = 8;
    std::vector<std::vector<std::string>> board;
    std::vector<std::vector<std::string>> squares;
    std::vector<std::vector<sf::Texture>> textures;
    std::vector<std::vector<sf::Sprite>> sprites;

    public:

    void drawBoard(bool color) //Draws board based on player's choice of color 
    {

    }



};

class black
{
    private:

    public:
};

class white
{
    private:

    public:
};

void startMenu(board& C, int& botELO, bool& color, bool& over);


void play(board& C, black& B, white& W, int& botELO, bool& over);