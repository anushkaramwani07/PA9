#pragma once

#include "Header.hpp"

class Player : public sf::CircleShape
{
public:
	//constructor
	Player(const float& rad, const Vector2f& pos, sf::Texture mTexture, sf::RenderWindow& window) : mSprite(mTexture), CircleShape(rad)
	{
		mColor = sf::Color(236, 255, 173);
		mSize = rad;
		xPos = pos.x;
		yPos = pos.y;
		this->setFillColor(sf::Color(236, 255, 173));
		this->setPosition(pos);
		this->setPosition(pos);

		/*mTexture.loadFromFile("spider.png");
		mSprite.setTexture(mTexture);
		mSprite.setScale({4.f, 1.6f});*/
	}

	////destructor
	//~Player();

	//setters
	void setXPos(double newXPos);
	void setYPos(double newYPos);
	void setmSprite(sf::RenderWindow& window);

	//getters
	double getXPos();
	double getYPos();

private:
	sf::Color mColor;
	float mSize;
	double xPos;
	double yPos;
	sf::Texture mTexture;
	sf::Sprite mSprite;
};
