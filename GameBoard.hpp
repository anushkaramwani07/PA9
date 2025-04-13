#pragma once

#include "Header.hpp"

class GameBoard : public RectangleShape
{
public:
	GameBoard(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) : RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

	void setGameBoard(sf::RenderWindow& window);

private:
};
