#include "Enemy.hpp"

void Enemy::rotateSprite(string direction)
{
	if (direction == "right")
	{
		mSprite.setScale(Vector2f(-1, -1));
	}
	else if (direction == "down")
	{

	}
	else if (direction == "up")
	{

	}
	else if (direction == "left")
	{
		mSprite.setRotation(sf::degrees(0));
	}
}

bool Enemy::checkIfPlayer(Player p)
{
	if (p.getXPos() == this->getXPos())
	{
		if (p.getYPos() == this->getYPos())
		{
			return true;
		}
	}
	return false;
}

void Enemy::moveEnemy(Player p)
{
	if (p.getXPos() > this->getXPos())
	{
		this->setXPos(this->getXPos() + 100);
		this->rotateSprite("right");
	}
	else if (p.getXPos() < this->getXPos())
	{
		this->setXPos(this->getXPos() - 100);
		this->rotateSprite("left");
	}	
	else if (p.getYPos() > this->getYPos())
	{
		this->setYPos(this->getYPos() + 100);
		this->rotateSprite("up");
	}
	else if (p.getYPos() < this->getYPos())
	{
		this->setYPos(this->getYPos() - 100);
		this->rotateSprite("down");
	}
}
