#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <iostream>
#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Entities/Data/ISFSObject.h"
#include "Entities/IMMOItem.h"
#include "Entities/Variables/SFSUserVariable.h"
#include "Requests/SetUserVariablesRequest.h"
#include "Requests/JoinRoomRequest.h"
#include "Requests/ExtensionRequest.h"

#include "cocos2d.h"
#include "NewSceneData.h"
#include "BaseScene.h"
#include "GameObjects/Starship.h"

class AppDelegate;
class GameScene : public BaseScene
{
public:
	const int SCROLL_AREA_PADDING = 15;
public:
	int m_clientServerLag;
protected:
	boost::shared_ptr<ISFSObject> starsShipModels;
	boost::shared_ptr<ISFSObject> weaponsShipModels;

	bool isThrustKeyDown;
	bool isFire1KeyDown;

	float offsetX;
	float offsetY;
	cocos2d::Node* rootNode;
	cocos2d::Sprite* background;
	cocos2d::Sprite* foreground;

	Starship* myStarship;
	boost::shared_ptr<std::map<long int, Starship*>> starships;

	float gameTime;	
public:
	static NewSceneData createScene();

	virtual ~GameScene();

	void scrollBackground(float scrollX, float scrollY);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void setup(boost::shared_ptr<ISFSObject> starsShipModels, boost::shared_ptr<ISFSObject> weaponsModels);

	void setAppDelegate(AppDelegate* appDelegate);

	void update(float deltaTime);

	void updateShip(Starship* ship);

	void setStarshipRotating(long int userId, long r);

	void createStarship(long int userId, std::string userName, bool isMine, std::string type);

	void createWeaponShot(long int id, std::string type, float x, float y, float vx, float vy, int elapsed);

	void setStarshipPosition(long int userId, float x, float y, float vx, float vy, float d, bool t, int elapsed);

	void removeStarship(long int userId);

	void removeWeaponShot(long int weaponId);

	void explodeWeaponShot(long int shotId, long int posX, long int posY);
};

#endif // !__GAME_SCENE_H__