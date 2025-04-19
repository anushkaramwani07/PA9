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

//setters
void Player::setXPos(double newXPos)
{
	xPos = newXPos;

	Vector2f pos(this->getPosition());
	pos.x = newXPos;
	this->setPosition(pos);
}
void Player::setYPos(double newYPos)
{
	yPos = newYPos;

	Vector2f pos(this->getPosition());
	pos.y = newYPos;
	this->setPosition(pos);	
}

void Player::setSprite(sf::RenderWindow& window, sf::Texture texture)
{
	mSprite.setTexture(texture, false);
	mSprite.setScale(Vector2f(0.125, 0.125));
	mSprite.setPosition(Vector2f(xPos-15, yPos-15));
	window.draw(mSprite);
}

// getters
double Player::getXPos()
{
	return this->xPos;
}
double Player::getYPos()
{
	return this->yPos;
}
