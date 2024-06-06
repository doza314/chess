#include "chess.hpp"

void startMenu(board& C, player& P, bot& BOT, bool& color, bool& over) 
{
    sf::RenderWindow window(sf::VideoMode(400,300), "CHESS");
    sf::RectangleShape background(sf::Vector2f(400, 300));
    background.setFillColor(sf::Color(255, 255, 255, 128));
    background.setPosition(0, 0);

    sf::Sprite logo;
    sf::Texture logoTexture;
    logoTexture.loadFromFile("src/res/chess.png");
    logo.setTexture(logoTexture);
    logo.setPosition(-50, 0);

    button black;
    black.coords = { 150, 100 };
    black.options = 0;
    black.name = "black";
    black.textureFile += black.name + ".png";

    button white;
    white.coords = { 200, 100};
    white.options = 1;
    white.name = "white";
    white.textureFile += white.name + ".png";

    button play;
    play.coords = { 150, 200 };
    play.name = "play";
    play.options = 2;
    play.textureFile += play.name + ".png";


    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                over = true;
            }
        }
        if (black.checkClick(window))
        {
            P.setColor(0);
        }

        if (white.checkClick(window))
        {
            P.setColor(1);
        }
        if (play.checkClick(window))
        {
            window.close();
        }

        if (window.isOpen())
        {
            window.clear();
            window.draw(background);
            window.draw(logo);
            black.drawButton(window);
            white.drawButton(window);
            play.drawButton(window);
            window.display();
        }
    }
}

void play(board& C, player& P, bot& BOT, bool& over)
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "CHESS");
    
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
    boardTexture.loadFromFile("src/res/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(0, 0);
    boardSprite.setScale(0.4, 0.4);
    

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                over = true;
            }
        }
        if (window.isOpen())
        {
            window.clear();
            window.draw(boardSprite);
            window.display();
        }
    }
}

void endMenu(board& C, player& P, bot& BOT, bool& color, bool& over)
{

}

