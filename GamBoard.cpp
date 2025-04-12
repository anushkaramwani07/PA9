#include "GameBoard.hpp"

void GameBoard::displayBoard(sf::RenderWindow& window)
{
    GameBoard board(sf::Vector2f(window.getSize().x, window.getSize().y),
        sf::Vector2f(0, 0), sf::Color::White); //creating a white backround
    //now i will create the checkered effect

    //window.getSize().x / 8, window.getSize().y / 8

    //row 1
    //GameBoard b1(sf::Vector2f(window.getSize().x / 8, window.getSize().y / 8), sf::Vector2f(0, 0), sf::Color::Black);
    GameBoard b1(sf::Vector2f(30, 30), sf::Vector2f(0, 0), sf::Color::Black);
    GameBoard b2(sf::Vector2f(30, 30), sf::Vector2f(60, 0), sf::Color::Black);
    GameBoard b3(sf::Vector2f(30, 30), sf::Vector2f(120, 0), sf::Color::Black);
    GameBoard b4(sf::Vector2f(30, 30), sf::Vector2f(180, 0), sf::Color::Black);

    //row 2
    //GameBoard b1(sf::Vector2f(window.getSize().x / 8, window.getSize().y / 8), sf::Vector2f(0, 0), sf::Color::Black);
    GameBoard b5(sf::Vector2f(30, 30), sf::Vector2f(30, 30), sf::Color::Black);
    GameBoard b6(sf::Vector2f(30, 30), sf::Vector2f(90, 30), sf::Color::Black);
    GameBoard b7(sf::Vector2f(30, 30), sf::Vector2f(150, 30), sf::Color::Black);
    GameBoard b8(sf::Vector2f(30, 30), sf::Vector2f(210, 30), sf::Color::Black);
    //row 3
    //row 4
    //row 5
    //row 6
    //row 7
    //row 8


    window.draw(board);
    window.draw(b1);
    window.draw(b2);
    window.draw(b3);
    window.draw(b4);
    window.draw(b5);
    window.draw(b6);
    window.draw(b7);
    window.draw(b8);
}
