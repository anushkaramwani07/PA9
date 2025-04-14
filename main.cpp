#include "Maze.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    Player main(20.f, Vector2f(30, 30), sf::Color(236, 255, 173));
    Maze board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::White);
    sf::Font font("Game Bubble.ttf");

    int gameDiff = 0, moveX = 1, moveY = 1;

    // easy, medium, hard
    // we want "enimies" that they can't always see and when they jump into the spot they lose
    // they can't see they maze instead they are blindly going through it maybe with obsticles

    //creating a font to use to display texts
 
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
                board.easyMaze(window);
                gameDiff = 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) // medium
            {
                gameDiff = 2;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) // hard
            {
                gameDiff = 3;
            }
        }
        else // change screen because game difficulty has been selected
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                //.move({ 0, 0.03 });
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
                    
                }
            }

            board.setMaze(window, font, main);
        }
        window.display();
    }
}
