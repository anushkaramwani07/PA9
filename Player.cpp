/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#include "Player.hpp"

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
void Player::rotateSprite(string direction)
{
	if (direction == "down")
	{
		mSprite.setRotation(sf::degrees(0));
	}
	else if(direction == "up")
	{
		mSprite.setRotation(sf::degrees(180));
	}
	else if (direction == "right")
	{
		mSprite.setRotation(sf::degrees(270));
	}
	else if (direction == "left")
	{
		mSprite.setRotation(sf::degrees(90));
	}
}

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
void Player::setXPos(double newXPos)
{
	xPos = newXPos;

	Vector2f pos(this->getPosition());
	pos.x = newXPos;
	this->setPosition(pos);
}
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
void Player::setYPos(double newYPos)
{
	yPos = newYPos;

	Vector2f pos(this->getPosition());
	pos.y = newYPos;
	this->setPosition(pos);	
}
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
void Player::setSprite(sf::RenderWindow& window, sf::Texture texture)
{
	mSprite.setTexture(texture, false);
	mSprite.setScale(Vector2f(0.125, 0.125));
	mSprite.setOrigin(Vector2f(319, 266));
	mSprite.setPosition(Vector2f(xPos + 20, yPos + 20));
	window.draw(mSprite);
}

// getters
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
double Player::getXPos()
{
	return this->xPos;
}
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
double Player::getYPos()
{
	return this->yPos;
}
