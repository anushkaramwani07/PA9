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

	//difficulties
	void easyMaze();
	void mediumMaze();
	void hardMaze();

	void gameMenu(sf::RenderWindow& window, sf::Font font);

	bool checkSpot(Player p, int x, int y);

	int checkWin(sf::RenderWindow& window, sf::Font font, int x, int y);

	//setters
	void setPath(int newPath);
	void setBlacked(int newBlock);

	//getters
	int getPath();
	int getBlocked();

private:
	int mPaths;
	int mBlocked;
	int arrBoard[8][8]; // [row][col]
};
