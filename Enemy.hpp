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
#include "Player.hpp"

class Enemy : public Player
{
public:
	/*************************************************************
	* Function: Enemy()
	* Date Created: 4/20/25
	* Date Last Modified: 4/21/25
	* Description: constsructor for enemy
	* Input parameters: const float& rad, const Vector2f& pos, 
				sf::Texture texture
	* Returns: nothing
	* Preconditions: none
	* Postconditions: none
	*************************************************************/
	Enemy(const float& rad, const Vector2f& pos, sf::Texture texture) : Player(rad, pos, texture) 
	{
		mDamage = 0;
	};

	/*************************************************************
 	* Function: Enemy()
 	* Function: ~Enemy()
 	* Date Created: 4/20/25
 	* Date Last Modified: 4/20/25
 	* Description: destructor for the Enemy
 	* Input parameters: none
 	* Returns: nothing
 	* Preconditions: none
 	* Postconditions: none
 	*************************************************************/
 	~Enemy() {};

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
	bool checkIfPlayer(Player p);

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
	void moveEnemy(Player p);

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
	void setDamage(int newDamage);

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
	int getDamage();

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
	int medium(int move);

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
	bool checkEnd();

private:
	int mDamage;
};
