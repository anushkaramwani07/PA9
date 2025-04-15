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

// getters
double Player::getXPos()
{
	return this->xPos;
}
double Player::getYPos()
{
	return this->yPos;
}
