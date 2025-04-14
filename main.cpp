#include "Maze.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    Player main(20.f, Vector2f(30, 30), sf::Color(236, 255, 173));
    Maze Board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::White);
    sf::Font font("Game Bubble.ttf");

    int gameDiff = 0, moveX = 0, moveY = 0;

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
            


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
            {
                Board.easyMaze(window);
                gameDiff = 1;
            }
        }
        else // change screen because game difficulty has been selected
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                //.move({ 0, 0.03 });
                main.setYPos(main.getYPos() + 100);
                ++moveY;
            }

            Board.setMaze(window, font, main);
        }
        window.display();
    }
}
