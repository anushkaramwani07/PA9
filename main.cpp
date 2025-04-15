#include "Maze.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    Player main(20.f, Vector2f(30, 30));
    Maze board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::White);
    sf::Font font("Game Bubble.ttf");

    int gameDiff = 0, moveX = 1, moveY = 1, moves = 0; //keep tally on number of moves so we can say they got the best score
    sf::Clock delay;

    // we want "enimies" that they can't always see and when they jump into the spot they lose
    // they can't see they maze instead they are blindly going through it maybe with obsticles
 
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


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) // easy
            {
                board.easyMaze();
                gameDiff = 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) // medium
            {
                //board.mediumMaze();
                gameDiff = 2;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) // hard
            {
                //board.hardMaze();
                gameDiff = 3;
            }
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
            gameDiff = board.checkWin(window, font, moveX, moveY);
        }

        window.display();
    }
}
