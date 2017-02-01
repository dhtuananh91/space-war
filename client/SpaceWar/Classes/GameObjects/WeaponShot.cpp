#include "WeaponShot.h"

USING_NS_CC;
WeaponShot* WeaponShot::createBullet()
{
	return createGameItem<WeaponShot>("weapon_torpedo_0001.png");
}

WeaponShot::WeaponShot() : GameItem()
{
	isAnimation = false;
}

void WeaponShot::explode(float posX, float posY)
{
	velocity = cocos2d::Vec2::ZERO;
	xx = posX;
	yy = posY;
	isAnimation = true;

	Animation* animation = AnimationCache::getInstance()->getAnimation("exp");
	runAction(Sequence::createWithTwoActions(Animate::create(animation), RemoveSelf::create()));
}

void WeaponShot::update(float deltaTime) 
{
	setRotation(getRotation() + CC_RADIANS_TO_DEGREES(M_PI * 2) * deltaTime);
}