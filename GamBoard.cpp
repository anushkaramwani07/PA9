#include "GameBoard.hpp"

void GameBoard::setGameBoard(sf::RenderWindow& window)
{
    sf::Vector2f size(30, 30);
    sf::Vector2f pos;
    
    int yPos = 0;

    while (yPos < 8)
    {
        int xPos = 0;

        if (yPos == 0 || yPos == 2 || yPos == 4 || yPos == 6)
        {
            while (xPos < 4)
            {
                //pos = { xPos * 60, yPos * 30 };
                pos.x = xPos * 60;
                pos.y = yPos * 30;

                this->setSize(size);
                this->setFillColor(sf::Color::White);
                this->setPosition(pos);

                window.draw(*this);

                ++xPos;
            }
        }
        else if (yPos == 1 || yPos == 3 || yPos == 5 || yPos == 7)
        {
            while (xPos < 4)
            {
                //pos = { xPos * 60 + 30, yPos * 30 };

                pos.x = xPos * 60 + 30;
                pos.y = yPos * 30;

                this->setSize(size);
                this->setFillColor(sf::Color::White);
                this->setPosition(pos);

                window.draw(*this);

                ++xPos;
            }
        }

        ++yPos;
    }
}
