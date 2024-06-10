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

    std::vector<std::string> board;
    std::vector<std::string> squares;

    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
    std::vector< std::vector<int> > coords;   // {wR, wN, wB, wQ, wK, wB, wN, wR,
                                            //  wP, wP, wP, wP, wP, wP, wP, wP,
                                            //  bP, bP, bP, bP, bP, bP, bP, bP,
                                            //  bR, bN, bB, bQ, bK, bB, bN, bR};

    public:

    void drawBoard(bool color) //Draws board based on player's choice of color 
    {
        sf::Texture pieceTexture;
        sf::Sprite pieceSprite;
        if (color == 0)
        {
            squares  = {"wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR",
                        "wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP"
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP",
                        "bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR"};
            for (auto piece : squares)
            {
                if (piece != "-")
                {
                    pieceTexture.loadFromFile("src/res/" + piece + ".png");
                    pieceSprite.setTexture(pieceTexture);
                    textures.push_back(pieceTexture);
                }   
            }
            
        }
        else if (color == 1)
        {
            squares  = {"bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR",
                        "bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP"
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "-",  "-",  "-",  "-",  "-",  "-",  "-",  "-",
                        "wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP",
                        "wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR"};
        }
        

        }
    };

class player
{
    private:
        int color = 1; // 0 = black, 1 = white
        bool inCheck = false;
        bool inMate = false;
        std::vector<std::string> pieces = {"p", "p", "p", "p", "p", "p", "p", "p", 
                                           "r", "n", "b", "k", "q", "b", "n", "r"};
    public:
        void setColor(int c)
        {
            color = c;
        }

        int getColor()
        {
            return color;
        }
        
};

class bot
{
    private:

    public:
};

class button
{
    private:

    public:
        std::vector<int> coords = {0, 0};
        std::vector<int> size = {50, 50};
        bool pressed = false;
        bool clicked = false;
        bool inside = false;
        std::string textureFile = "src/res/";
        std::string names[5] = {"black", "white", "play", "restart", "exit"};
        int options = 0;
        std::string name;
        sf::Texture texture;
        sf::Sprite sprite;

        void drawButton(sf::RenderWindow& target) //Draws button in window
        {   
            if (!texture.loadFromFile(textureFile)) // Load texture from file
            {
                //std::cout << "ERROR" << std::endl;
            }

            sprite.setTexture(texture);
            sprite.setScale(0.5, 0.5);
            sprite.setPosition(coords[0], coords[1]);
            target.draw(sprite);
        }

        bool checkClick(sf::RenderWindow& target)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(target);

                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
                {
                    if (mousePos.x > coords[0] && mousePos.x < coords[0] + size[0] && mousePos.y > coords[1] &&  mousePos.y < coords[1] + size[1])
                    {
                        pressed = true;
                        inside = true;
                        textureFile = "src/res/";

                        if (name != names[options] + " pressed.png") 
                        {
                            name += " pressed.png";
                        }
                        textureFile += name;
                        drawButton(target);
                    }
                    

                    if (mousePos.x < coords[0] || mousePos.x > coords[0] + size[0] ||
                        mousePos.y < coords[1] || mousePos.y > coords[1] + size[1] && pressed == true)
                    {
                        inside = false;
                    }
                    
                    return false; 
                } 

                if (pressed)
                {   
                    pressed = false;
                    textureFile = "src/res/";
                    name = names[options];
                    textureFile += name + ".png";
                    drawButton(target);

                    if (inside)
                    {
                        clicked = true;                       
                    }
                }
                
                if (clicked) 
                {
                    clicked = false;                
                    return true; 
                }

            return false; // Not pressed or not within bounds
        }
};

void startMenu(board& C, player& P, bot& BOT, bool& color, bool& over);


void play(board& C, player& P, bot& BOT, bool& over);