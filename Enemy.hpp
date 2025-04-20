#pragma once
#include "Player.hpp"

class Enemy : public Player
{
public:
	Enemy(const float& rad, const Vector2f& pos, sf::Texture texture) : Player(rad, pos, texture)
	{

	};

	//void kill(Player& player); // to attack
};
