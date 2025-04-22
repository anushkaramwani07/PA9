/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#include "Test.hpp"

int main()
{
    // test cases ////////////////////////////////////////////////////////
    Test t;
    //t.testMazeConstructor();
    //t.testSetSprite();
    //t.testCheckSpot();
    //t.testRotateSprite();
    t.testCheckWin();
    //////////////////////////////////////////////////////////////////////


    // Declaring variables /////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Lets Play The Maze Game!");

    // Player
    sf::Texture spider("spider.png", false, sf::IntRect({ 0,0 }, { 638,532 }));
    Player main(20.f, Vector2f(30, 30), spider);

    // Game Board
    sf::Font font("Game Bubble.ttf");
    Maze board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::Transparent);

    // Enemy
    sf::Texture enemyTexture("enemy.png", false, sf::IntRect({ 0, 0 }, { 382,661 }));
    Enemy enemy(20.f, Vector2f(30, 30), enemyTexture);

    // other
    int gameDiff = 0, enemyMove = 0, moveX = 1, moveY = 1, moves = 0; //keep tally on number of moves so we can say they got the best score
    sf::Clock delay;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // we want "enimies" that they can't always see and when they jump into the spot they lose
 
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        //the game difficulty hasn't been selected
        if (gameDiff == 0)
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
                board.hardMaze();
                main.setXPos(main.getXPos() + 300);
                main.setYPos(main.getYPos() + 400);
                moveY = 5;
                moveX = 4;
                gameDiff = 3;
            }
        }
        // they won the game
        else if (gameDiff == 10)
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

            text.setString("Play Again??? (Press F)");
            text.setCharacterSize(50);
            center = text.getGlobalBounds().size / 2.f;
            bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,700 });
            text.setFillColor(sf::Color(129, 252, 234));
            window.draw(text);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
            {
                gameDiff = 0;
            }
        }
        // they lost the game
        else if (gameDiff == -1)
        {
            sf::Text text(font);

            //displaying the losing text
            text.setString("GAME");
            text.setCharacterSize(200);
            auto center = text.getGlobalBounds().size / 2.f;
            auto bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,300 });
            text.setFillColor(sf::Color(181, 18, 18));

            window.draw(text);

            text.setString("OVER!!!");
            center = text.getGlobalBounds().size / 2.f;
            bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,500 });
            text.setFillColor(sf::Color(181, 18, 18));
            window.draw(text);   


            text.setString("Try Again??? (Press F)");
            text.setCharacterSize(50);
            center = text.getGlobalBounds().size / 2.f;
            bounds = center + text.getLocalBounds().position;
            text.setOrigin(bounds);
            text.setPosition(sf::Vector2f{ 400,700 });
            text.setFillColor(sf::Color(129, 252, 234));
            window.draw(text);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
            {
                gameDiff = 0;
            }

        }
        // change screen because game difficulty has been selected
        else
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
                        main.rotateSprite("down");
                    }
                    else
                    {
                        --moveY;
                    }
                    delay.restart();
                }

                enemyMove = 1;
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
                        main.rotateSprite("up");
                    }
                    else
                    {
                        ++moveY;
                    }
                    delay.restart();
                }
                enemyMove = 1;
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
                        main.rotateSprite("left");
                    }
                    else
                    {
                        ++moveX;
                    }
                    delay.restart();
                }
                enemyMove = 1;
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
                        main.rotateSprite("right");
                    }
                    else
                    {
                        --moveX;
                    }
                    delay.restart();
                }
                enemyMove = 1;
            }
           
            if (gameDiff == 3 && enemyMove == 1)//hard level
            {
                enemy.moveEnemy(main);
                enemyMove = 0;
            }

            board.setMaze(window, font, main);
            main.setSprite(window, spider);

            if (gameDiff == 3)
            {
                enemy.setSprite(window, enemyTexture);
            }
            if (gameDiff == 3 && enemy.checkIfPlayer(main) == true && delay.getElapsedTime() > sf::seconds(0.25))
            {
                enemy.setDamage(enemy.getDamage() + 1);

                enemy.setXPos(30);
                enemy.setYPos(730);

                delay.restart();
            }
            if (enemy.getDamage() == 3)
            {
                gameDiff = -1;
            }

            gameDiff = board.checkWin(window, font, moveX, moveY, gameDiff);
        }

        window.display();
    }
}
