#pragma once

#include <string>
#include <iostream>

using std::string;

class Player
{
public:
	//constructor
	Player(double newXPos, double newYPos) : xPos(newXPos), yPos(newYPos) {};

	//destructor
	~Player();

	//setters
	void setXPos(double newXPos);
	void setYPos(double newYPos);

	//getters
	double getXPos();
	double getYPos();

private:
	double xPos;
	double yPos;
	//graphic
};
