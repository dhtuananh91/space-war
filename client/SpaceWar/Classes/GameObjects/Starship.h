#ifndef __STAR_SHIP_H__
#define __STAR_SHIP_H__

#include "GameItem.h"
class Starship : public GameItem
{
public:
	std::string userName;
	bool isMine;
	bool _doThrust;
	int thrusterValue;
	int rotatingDir;
public:
	static Starship* createShip(std::string type);
	Starship();
	void doThrust(bool value);
	void normalizedSpeed();
	float rotationSpeed();
	float thrustAcceleration();
	float maxSpeed();
};

#endif // !__STAR_SHIP_H__