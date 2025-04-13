#include "GameBoard.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Lets Play The Maze Game!");
    GameBoard Board(Vector2f(0, 0), Vector2f(0, 0), sf::Color::White);

    // easy, medium, hard
    // we want "enimies" that they can't always see and when they jump into the spot they lose
    // they can't see they maze instead they are blindly going through it maybe with obsticles


    //creating a font to use to display texts
    sf::Font font("Game Bubble.ttf");    
    sf::Text text(font);
 
    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        // set the string to display
        text.setString("Hello world");

        // set the character size
        text.setCharacterSize(50); // in pixels, not points!

        // set the color
        text.setFillColor(sf::Color(50, 143, 168));

        // set the text style
        text.setStyle(sf::Text::Regular);
        
        window.clear();
        Board.setGameBoard(window);
        window.draw(text);
        window.display();
    }
}
