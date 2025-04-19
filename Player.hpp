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
		mColor = sf::Color(236, 255, 173);
		mSize = rad;
		xPos = pos.x;
		yPos = pos.y;
		this->setFillColor(sf::Color(236, 255, 173));
		this->setPosition(pos);
		this->setPosition(pos);
	}


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
	//setters
	void setXPos(double newXPos);
	void setYPos(double newYPos);
	void setSprite(sf::RenderWindow& window, sf::Texture texture);

	//getters
	double getXPos();
	double getYPos();

private:
	sf::Color mColor;
	float mSize;
	double xPos;
	double yPos;
	sf::Sprite mSprite;
};
