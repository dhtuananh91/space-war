#ifndef __NEW_SCENE_DATA_H__
#define __NEW_SCENE_DATA_H__

#include "cocos2d.h"

struct NewSceneData
{
	cocos2d::Scene* scene;
	cocos2d::Layer* layer;

	NewSceneData(cocos2d::Scene* __scene, cocos2d::Layer* __layer) { scene = __scene; layer = __layer; }
};

#endif // !__NEW_SCENE_DATA_H__