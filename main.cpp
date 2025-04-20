/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#include "maze.hpp"
#include "Enemy.hpp"
int main()
{
    // test cases ////////////////////////////////////////////////////////
   // Test t;
    //t.testMazeConstructor();
    //////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    sf::Texture mTexture("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    sf::Sprite spider(mTexture);

    sf::Texture enemyTexture;
    Enemy enemy(20.f, Vector2f(30,30), enemyTexture);
    enemyTexture.loadFromFile("enemy.png", false, sf::IntRect({ 0, 0 }, { 638,532 }));
    enemy.setTexture(&enemyTexture);
    window.draw(enemy);
    //window.draw(enemy);

    sf::Font font("Game Bubble.ttf");
    Player main(20.f, Vector2f(30, 30), mTexture);
    Maze board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::White);

    int gameDiff = 0, moveX = 1, moveY = 1, moves = 0; //keep tally on number of moves so we can say they got the best score
    sf::Clock delay;
      
    
    // we want "enimies" that they can't always see and when they jump into the spot they lose

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        if (gameDiff == 0) //the game difficulty hasn't been selected
        {
            board.gameMenu(window, font);

            //easy
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) // easy
            {
                board.easyMaze();
                gameDiff = 1;
            }
            //medium
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) // medium
            {
                board.mediumMaze();
                main.setYPos(main.getYPos() + 300);
                moveX = 1;
                moveY = 4;
                gameDiff = 2;
            }
            //hard
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) // hard
            {
                //board.hardMaze();
                gameDiff = 3;
            }
        }
        else if (gameDiff == 10) // they won the game
        {
            //displaying firework image
            sf::Texture texture("fireworks.jpg", false, sf::IntRect({ 0, 0 }, { 800, 800 }));
            texture.setSmooth(true);
            sf::Sprite sprite(texture);
            //sprite.setTextureRect(sf::IntRect({ 336, 0 }, { 1136, 800 }));
            //sprite.setColor(sf::Color(158, 76, 73, 128));
            window.draw(sprite);

            sf::Text text(font);

            //displaying the winning text
            text.setString("You Win");
            text.setCharacterSize(200);
            auto center = text.getGlobalBounds().size / 2.f;
            auto bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,400 });
            text.setFillColor(sf::Color(242, 242, 145));

            window.draw(text);
        }
        else if (gameDiff == -1) // they lost the game
        {
            sf::Text text(font);

            //displaying the losing text
            text.setString("YOU LOSE");
            text.setCharacterSize(200);
            auto center = text.getGlobalBounds().size / 2.f;
            auto bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,400 });
            text.setFillColor(sf::Color(181, 18, 18));

            window.draw(text);
        }
        else // change screen because game difficulty has been selected
        {
            // move down
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && delay.getElapsedTime() > sf::seconds(0.25)) // adds a delay after each button press
                // this makes it so the player doesn't mmove that fast
            {
                if (moveY < 8)
                {
                    ++moveY;

                    if (board.checkSpot(main, moveX, moveY) == true)
                    {
                        main.setYPos(main.getYPos() + 100);
                    }
                    else
                    {
                        --moveY;
                    }
                    delay.restart();
                }
            }
            // move up
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && delay.getElapsedTime() > sf::seconds(0.25))
            {
                if (moveY > 1)
                {
                    --moveY;

                    if (board.checkSpot(main, moveX, moveY) == true)
                    {
                        main.setYPos(main.getYPos() - 100);
                    }
                    else
                    {
                        ++moveY;
                    }
                    delay.restart();
                }
            }
            // move left
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && delay.getElapsedTime() > sf::seconds(0.25))
            {
                if (moveX > 1)
                {
                    --moveX;

                    if (board.checkSpot(main, moveX, moveY) == true)
                    {
                        main.setXPos(main.getXPos() - 100);
                    }
                    else
                    {
                        ++moveX;
                    }
                    delay.restart();
                }
            }
            // move right
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && delay.getElapsedTime() > sf::seconds(0.25))
            {
                if (moveX < 8)
                {
                    ++moveX;

                    if (board.checkSpot(main, moveX, moveY) == true)
                    {
                        main.setXPos(main.getXPos() + 100);
                    }
                    else
                    {
                        --moveX;
                    }
                    delay.restart();
                }
            }

            board.setMaze(window, font, main);
            main.setSprite(window, mTexture);

            //gameDiff = board.checkWin(window, font, moveX, moveY, gameDiff);
        }

        window.display();
    }
}
