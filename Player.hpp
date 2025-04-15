#pragma once

#include "Header.hpp"

class Player : public sf::CircleShape
{
public:
	//constructor
	Player(const float& rad, const Vector2f& pos) : CircleShape(rad)
	{
		mColor = sf::Color(236, 255, 173);
		mSize = rad;
		xPos = pos.x;
		yPos = pos.y;
		this->setFillColor(sf::Color(236, 255, 173));
		this->setPosition(pos);
	}

	////destructor
	//~Player();

	//setters
	void setXPos(double newXPos);
	void setYPos(double newYPos);

	//getters
	double getXPos();
	double getYPos();

private:
	sf::Color mColor;
	float mSize;
	double xPos;
	double yPos;
};
