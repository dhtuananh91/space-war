#ifndef __GAME_ITEM_H__
#define __GAME_ITEM_H__

#include <cocos2d.h>
#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Entities/Data/ISFSObject.h"

template <class T> 
T* createGameItem(const std::string& filename) {
	T *sprite = new (std::nothrow) T();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

class GameItem : public cocos2d::Sprite
{
public:
	long int id;
	float xx;
	float yy;
	cocos2d::Vec2 velocity;
	float deltaTime;
	boost::shared_ptr<ISFSObject> settings;
public:	
	GameItem();
};

#endif // !__GAME_ITEM_H__