#pragma once
#include "Player.hpp"

class Enemy : public Player
{
public:
	Enemy(const float& rad, const Vector2f& pos, sf::Texture texture) : Player(rad, pos, texture) 
	{
		mDamage = 0;
	};

	//void kill(Player& player); // to attack

	void rotateSprite(string direction) override;

	bool checkIfPlayer(Player p);

	void moveEnemy(Player p);



private:
	int mDamage;
};
