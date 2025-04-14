#pragma once

#include "Header.hpp"
#include "Player.hpp"

class Maze : public RectangleShape
{
public:
	Maze(const Vector2f& size, const Vector2f& pos, const sf::Color& color) : RectangleShape(size)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8;j++)
			{
				arrBoard[i][j] = 0;
			}
		}
		mPaths = 0;
		mBlocked = 0;
		this->setFillColor(color);
		this->setPosition(pos);
	}

	void setMaze(sf::RenderWindow& window, sf::Font font, Player p);

	void easyMaze(sf::RenderWindow& window);

	void gameMenu(sf::RenderWindow& window, sf::Font font);

	//setters
	void setPath(int newPath);
	void setBlacked(int newBlock);

	//getters
	int getPath();
	int getBlocked();

private:
	int mPaths;
	int mBlocked;
	int arrBoard[8][8];
};
