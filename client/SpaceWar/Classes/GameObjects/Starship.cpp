#include "Starship.h"

USING_NS_CC;

Starship::Starship():GameItem()
{	
	this->userName = "";
	this->isMine = false;
	this->thrusterValue = 0;
	this->rotatingDir = 0;	
	this->_doThrust = false;	
}

void Starship::doThrust(bool value)
{
	this->_doThrust = value;
	this->thrusterValue = (value ? 2 : 0);
	// Play thrust animation
}

void Starship::normalizedSpeed()
{
	float speed = (float)sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
	if (speed > maxSpeed())
	{
		float direction = (float)atan2(velocity.y, velocity.x);
		float dir = direction;
		velocity.x = (float)cos(dir) * maxSpeed();
		velocity.y = (float)sin(dir) * maxSpeed();
	}
}

float Starship::rotationSpeed()
{
	return ((float)(*settings->GetInt("rotationSpeed").get()) * M_PI / 180.0f) / 1000.0f;
}

float Starship::thrustAcceleration()
{
	// Thrust accceleration is converted from pixels/sec2 to pixels/ms2
	return (float)(*settings->GetInt("thrustAccel").get()) / 1000000.0f;
}

float Starship::maxSpeed()
{
	// Speed is converted from pixels/sec to pixels/ms
	return (float)(*settings->GetInt("maxSpeed").get()) / 1000.0f;
}

Starship* Starship::createShip(std::string type) {
	if (!strcmp(type.c_str(), "Astro"))
		return createGameItem<Starship>("ship_astro_0001.png");
	if (!strcmp(type.c_str(), "Raptor"))
		return createGameItem<Starship>("ship_raptor_0001.png");
	if (!strcmp(type.c_str(), "Viking"))
		return createGameItem<Starship>("ship_viking_0001.png");
}