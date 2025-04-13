#include "GameBoard.hpp"

void GameBoard::setGameBoard(sf::RenderWindow& window)
{
    sf::Vector2f size(29.5, 29.5);
    sf::Vector2f pos;
    
    int yPos = 0; //the row we are at

    while (yPos < 8)
    {
        int xPos = 0; // which column we are in

        while (xPos < 8)
        {
            pos.x = xPos * 30; // x position
            pos.y = yPos * 30; // y postition

           /* this->setSize(size);
            this->setFillColor(sf::Color(23, 43, 53));
            this->setPosition(pos);*/


            this->setSize(size);
            this->setFillColor(sf::Color::Black);
            this->setOutlineThickness(0.5);
            this->setOutlineColor(sf::Color::White);
            this->setPosition(pos);

            window.draw(*this);

            ++xPos;
        }
        
        ++yPos;
    }
}
