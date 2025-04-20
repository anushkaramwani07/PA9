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

class Player : public sf::CircleShape
{
public:
	/*************************************************************
	* Function: Player()
	* Date Created: 4/14/25
	* Date Last Modified: 4/18/25
	* Description: constructor for the Player
	* Input parameters: const float& rad, const Vector2f& pos
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	Player(const float& rad, const Vector2f& pos, sf::Texture texture) : mSprite(texture), CircleShape(rad)
	{
		/*mColor = sf::Color::Transparent;
		mSize = rad;*/
		xPos = pos.x;
		yPos = pos.y;
		this->setFillColor(sf::Color::Transparent);
		this->setPosition(pos);
		this->setPosition(pos);
	}

	/*************************************************************
	* Function: rotateSprite()
	* Date Created: 4/20/25
	* Date Last Modified: 4/20/25
	* Description: rotates the player in the direction they move
	* Input parameters: sf::Texture texture, string direction
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void rotateSprite(sf::Texture texture, string direction);

	//setters
	/*************************************************************
	* Function: setXPos()
	* Date Created: 4/15/25
	* Date Last Modified: 4/16/25
	* Description: sets the x postion for player
	* Input parameters: double newXPos
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setXPos(double newXPos);
	/*************************************************************
	* Function: setYPos()
	* Date Created: 4/15/25
	* Date Last Modified: 4/16/25
	* Description: sets the y postion for player
	* Input parameters: double newYPos
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setYPos(double newYPos);
	/*************************************************************
	* Function: setXPos()
	* Date Created: 4/19/25
	* Date Last Modified: 4/19/25
	* Description: sets the sprites postion for player
	* Input parameters: sf::RenderWindow& window, sf::Texture texture
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	void setSprite(sf::RenderWindow& window, sf::Texture texture);

	//getters
	/*************************************************************
	* Function: getXPos()
	* Date Created: 4/15/25
	* Date Last Modified: 4/15/25
	* Description: gets the x postion for the player
	* Input parameters: none
	* Returns: xPos
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	double getXPos();
	/*************************************************************
	* Function: getYPos()
	* Date Created: 4/15/25
	* Date Last Modified: 4/15/25
	* Description: gets the y postion for the player
	* Input parameters: none
	* Returns: yPos
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	double getYPos();

private:
	/*sf::Color mColor;
	float mSize;*/
	double xPos;
	double yPos;
	sf::Sprite mSprite;
};
