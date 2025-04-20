/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#pragma once

#include "Header.hpp"
#include "Player.hpp"

class Maze : public RectangleShape
{
public:
	/*************************************************************
	* Function: Maze()
	* Date Created: 4/14/25
	* Date Last Modified: 4/18/25
	* Description: constructor for the maze
	* Input parameters: const Vector2f& size, const Vector2f& pos, const sf::Color& color
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
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

	/*************************************************************
	* Function: setMaze()
	* Date Created: 4/14/25
	* Date Last Modified: 4/20/25
	* Description: draws the maze and the cahracter
	*				constantly updating the game
	* Input parameters: sf::RenderWindow& window, sf::Font font, Player 
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setMaze(sf::RenderWindow& window, sf::Font font, Player p);

	//difficulties
	/*************************************************************
	* Function: easyMaze()
	* Date Created: 4/14/25
	* Date Last Modified: 4/18/25
	* Description: changes the arrBoard for easy mode
	* Input parameters: none
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/	
	void easyMaze();
	/*************************************************************
	* Function: mediumMaze()
	* Date Created: 4/14/25
	* Date Last Modified: 4/18/25
	* Description: changes the arrBoard for medium mode
	* Input parameters: none
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void mediumMaze();
	/*************************************************************
	* Function: hardMaze()
	* Date Created: 4/18/25
	* Date Last Modified: 4/21/25
	* Description: changes the arrBoard for hard mode
	* Input parameters: none
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void hardMaze();

	/*************************************************************
	* Function: gameMenu()
	* Date Created: 4/14/25
	* Date Last Modified: 4/18/25
	* Description: displays the game difficulty choices
	* Input parameters: sf::RenderWindow& window, sf::Font font
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void gameMenu(sf::RenderWindow& window, sf::Font font);

	/*************************************************************
	* Function: checkSpot()
	* Date Created: 4/15/25
	* Date Last Modified: 4/17/25
	* Description: determines if the spot the player wants to go it blocked
	*				and then marks it with -1 if it is
	* Input parameters: Player p, int x, int y
	* Returns: bool (true or false)
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	bool checkSpot(Player p, int x, int y);

	/*************************************************************
	* Function: checkWin()
	* Date Created: 4/15/25
	* Date Last Modified: 4/17/25
	* Description: constructor for the maze
	* Input parameters: sf::RenderWindow& window, sf::Font font, int x, int y, int gameDif
	* Returns: a number based on if the player has made it to the end
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	int checkWin(sf::RenderWindow& window, sf::Font font, int x, int y, int gameDif);

	/*************************************************************
	* Function: printBoard()
	* Date Created: 4/19/25
	* Date Last Modified: 4/19/25
	* Description: prints the arrBoard
	* Input parameters: none
	* Returns: mBlocked
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void printBoard();

	//setters
	/*************************************************************
	* Function: setPath()
	* Date Created: 4/14/25
	* Date Last Modified: 4/14/25
	* Description: setter for the private member mPaths
	* Input parameters: int newPath
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setPath(int newPath);
	/*************************************************************
	* Function: setBlocked()
	* Date Created: 4/14/25
	* Date Last Modified: 4/14/25
	* Description: setter for the private member mBlocked
	* Input parameters: int newBlock
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setBlacked(int newBlock);

	//getters
	/*************************************************************
	* Function: getPath()
	* Date Created: 4/14/25
	* Date Last Modified: 4/14/25
	* Description: getter for the private member mPaths
	* Input parameters: none
	* Returns: mPaths
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	int getPath();
	/*************************************************************
	* Function: getBlocked()
	* Date Created: 4/14/25
	* Date Last Modified: 4/14/25
	* Description: getter for the private member mBlocked
	* Input parameters: none
	* Returns: mBlocked
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	int getBlocked();

private:
	int mPaths; // the amount of ways for you to go
	int mBlocked; // the amount blocked
	int arrBoard[8][8]; // [row][col]
};
