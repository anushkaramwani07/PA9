#include "GameBoard.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 270, 270 }), "Lets Play!");
    GameBoard Board(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Color::White);
  
    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        Board.setGameBoard(window);
        window.display();
      }
    }
