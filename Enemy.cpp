/*******************************************************************************
 * Programmers: Abaigail Kubli and Anushka Ramwani
 * Class: CptS 122; Lab Section 10
 * Programming Assignment: 9 - A Graphical Game or Application
 * Date: 4/12/2025
 *
 * Description: Creating our own game using sfml and inheritance
 *
 ******************************************************************************/

#include "Enemy.hpp"

/*************************************************************
* Function: rotateSprite()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: rotates the enemy
* Input parameters: string direction
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Enemy::rotateSprite(string direction)
{
	if (direction == "right")
	{
		mSprite.scale(sf::Vector2f(-1.f, 1.f));
	}
	else if (direction == "left")
	{
		mSprite.setRotation(sf::degrees(0));
	}
}

/*************************************************************
* Function: checkIfPlayer()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: sees if player and enemy are in the same place
* Input parameters: Player p
* Returns: true or false
* Preconditions: none
* Postconditions: none
*************************************************************/
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

/*************************************************************
* Function: moveEnemy()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: moves the enemy on the board
* Input parameters: Player p
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Enemy::moveEnemy(Player p)
{
	if (p.getXPos() > this->getXPos())
	{
		this->setXPos(this->getXPos() + 100);
		//this->rotateSprite("right");
	}
	else if (p.getXPos() < this->getXPos())
	{
		this->setXPos(this->getXPos() - 100);
		//this->rotateSprite("left");
	}	
	else if (p.getYPos() > this->getYPos())
	{
		this->setYPos(this->getYPos() + 100);
	}
	else if (p.getYPos() < this->getYPos())
	{
		this->setYPos(this->getYPos() - 100);
	}
}

/*************************************************************
* Function: setDamage()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: setter for mDamage
* Input parameters: int newDamage
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void Enemy::setDamage(int newDamage)
{
	mDamage = newDamage;
}
/*************************************************************
* Function: getDamage()
* Date Created: 4/21/25
* Date Last Modified: 4/21/25
* Description: gets the mDamage
* Input parameters: none
* Returns: mDamage
* Preconditions: none
* Postconditions: none
*************************************************************/
int Enemy::getDamage()
{
	return this->mDamage;
}
