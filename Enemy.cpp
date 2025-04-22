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
	if (p.getXPos() == this->getXPos()) // are they at the same X
	{
		if (p.getYPos() == this->getYPos()) // are they also at the same Y
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
	if (p.getXPos() > this->getXPos()) // is the player at a column to the right of the enemy
	{
		this->setXPos(this->getXPos() + 100); 
	}
	else if (p.getXPos() < this->getXPos()) // is the player at a column to the left of the enemy
	{
		this->setXPos(this->getXPos() - 100);
	}	
	else if (p.getYPos() > this->getYPos()) // is the player at a lower row than the enemy??
	{
		this->setYPos(this->getYPos() + 100);
	}
	else if (p.getYPos() < this->getYPos()) // is the player at a higher row than the enemy??
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

/*************************************************************
* Function: medium()
* Date Created: 4/22/25
* Date Last Modified: 4/22/25
* Description: moves the enemy for the medium map
* Input parameters: int move
* Returns: move
* Preconditions: none
* Postconditions: none
*************************************************************/
int Enemy::medium(int move)
{
	// as the player moves, the skeleton should keep getting closer towards the "end".
//if skeleton gets there before player, player loses.
	if (move == 5)
	{
		this->setXPos(this->getXPos() + 100);
		move = 0;
	}
	return move;
}

/*************************************************************
* Function: checkEnd()
* Date Created: 4/22/25
* Date Last Modified: 4/22/25
* Description: sees if the enemy is at the end
* Input parameters: none
* Returns: true or false
* Preconditions: none
* Postconditions: none
*************************************************************/
bool Enemy::checkEnd()
{
	if (this->getYPos() == 730 && this->getXPos() == 730)
	{
		return true;
	}
	return false;
}
