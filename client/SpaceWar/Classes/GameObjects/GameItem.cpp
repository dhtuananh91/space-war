#include "GameItem.h"

GameItem::GameItem() : Sprite() {
	userId = -1;
	xx = 0;
	yy = 0;
	velocity = cocos2d::Vec2::ZERO;	
	deltaTime = 0;
	settings = NULL;
}