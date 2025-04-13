#include "GameBoard.hpp"

void GameBoard::setGameBoard(sf::RenderWindow& window)
{
    sf::Vector2f size(30, 30);
    sf::Vector2f pos;
    
    int yPos = 0; //the row we are at

    while (yPos < 8)
    {
        int xPos = 0; // which column we are in

        if (yPos == 0 || yPos == 2 || yPos == 4 || yPos == 6) // does this row start with a white square
        {
            while (xPos < 4)
            {
                pos.x = xPos * 60; // x position
                pos.y = yPos * 30; // y postition

                this->setSize(size);
                this->setFillColor(sf::Color::White);
                this->setPosition(pos);

                window.draw(*this);

                ++xPos;
            }
        }
        else if (yPos == 1 || yPos == 3 || yPos == 5 || yPos == 7) // does this row start with a black square
        {
            while (xPos < 4)
            {
                pos.x = xPos * 60 + 30; // x position
                pos.y = yPos * 30; // y postition

                this->setSize(size);
                this->setFillColor(sf::Color::White);
                this->setPosition(pos);

                window.draw(*this);

                ++xPos;
            }
        }

        ++yPos;
    }

    //bottom cyan row (make for the index (1,2,3,4,5,6,7,8))
    size.x = 270;
    size.y = 30;
    pos.x = 0;
    pos.y = 240;

    this->setSize(size);
    this->setFillColor(sf::Color::Cyan);
    this->setPosition(pos);

    window.draw(*this);

    //side cyan row (make for the index (A, B, C, D, E, F, G, H
    size.x = 30;
    size.y = 240;
    pos.x = 240;
    pos.y = 0;

    this->setSize(size);
    this->setFillColor(sf::Color::Cyan);
    this->setPosition(pos);

    window.draw(*this);

}
