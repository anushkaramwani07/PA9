#pragma once
#include "Player.hpp"

class Enemy : public Player
{
public:
	void kill(Player& player); // to attack
};
