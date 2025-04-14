#include "Player.hpp"

void Player::setYPos(double newYPos)
{
	yPos = newYPos;

	Vector2f pos(this->getPosition());
	pos.y = pos.y + 100;
	this->setPosition(pos);	
}

double Player::getYPos()
{
	return this->yPos;
}
