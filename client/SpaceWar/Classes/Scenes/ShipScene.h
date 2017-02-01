#ifndef __SHIP_SCENE_H__
#define __SHIP_SCENE_H__

#include <iostream>
#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Entities/Data/ISFSObject.h"
#include "Entities/Variables/SFSUserVariable.h"
#include "Requests/SetUserVariablesRequest.h"
#include "Requests/JoinRoomRequest.h"

#include "cocos2d.h"
#include "NewSceneData.h"
#include "BaseScene.h"

class AppDelegate;
class ShipScene : public BaseScene
{
public:
	boost::shared_ptr<ISFSObject> m_starsShipModels;
	boost::shared_ptr<ISFSObject> m_weaponsShipModels;
protected:
	std::vector<cocos2d::MenuItemImage*> m_shipModels;
	std::vector<cocos2d::MenuItemLabel*> m_shipNames;
	cocos2d::Label* m_title;	
	cocos2d::Menu* m_menu;
public:
	static NewSceneData createScene();

	virtual ~ShipScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(ShipScene);

	void setup(boost::shared_ptr<ISFSObject> starsShipModels, boost::shared_ptr<ISFSObject> weaponsModels);	

	virtual void setAppDelegate(AppDelegate* appDelegate);

	void onMenuClicked(int index);
};

#endif // !__SHIP_SCENE_H__