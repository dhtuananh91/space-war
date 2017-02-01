#ifndef __WEAPON_SHOT_H__
#define __WEAPON_SHOT_H__

#include "GameItem.h"
class WeaponShot : public GameItem
{
public:
	bool isAnimation;
public:
	static WeaponShot* createBullet();
	WeaponShot();
	void explode(float posX, float posY);
	void update(float deltaTime);
};

#endif // !__WEAPON_SHOT_H__