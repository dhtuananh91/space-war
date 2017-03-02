#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "GameObjects/GameItem.h"
#include "GameObjects/Starship.h"
#include "../ServerConnector.h"

USING_NS_CC;

std::string UV_MODEL = "sModel";		// Starship model
std::string UV_X = "x";					// x position
std::string UV_Y = "y";					// y position
std::string UV_VX = "vx";				// Velocity x component
std::string UV_VY = "vy";				// Velocity y component
std::string UV_DIR = "d";				// Ship direction
std::string UV_THRUST = "t";			// Ship's thruster is active
std::string UV_ROTATE = "r";			// Ship rotating direction

										// MMOITEM VARIABLES
std::string IV_TYPE = "iType";			// MMOItem type
std::string IV_MODEL = "iModel";		// MMOItem model
std::string IV_X = "x";					// x position
std::string IV_Y = "y";					// y position
std::string IV_VX = "vx";				// Velocity x component
std::string IV_VY = "vy";				// Velocity y component

std::string ITYPE_WEAPON = "weapon";	// MMOItem of type weapon
std::string RES_SHOT_XPLODE = "shot_xplode";

// REQUESTS TO SERVER
std::string REQ_ROTATE = "control.rotate";
std::string REQ_THRUST = "control.thrust";
std::string REQ_FIRE = "control.fire";

NewSceneData GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return NewSceneData(scene, layer);
}

void GameScene::setAppDelegate(AppDelegate * appDelegate)
{
	BaseScene::setAppDelegate(appDelegate);

	CCLOG("Register all event listener...");

	getSmartFox()->AddEventListener(SFSEvent::PING_PONG, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnPingPong, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::USER_VARIABLES_UPDATE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnUserVarsUpdate, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::PROXIMITY_LIST_UPDATE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnProximityListUpdate, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::EXTENSION_RESPONSE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnExtensionResponse, (unsigned long long)this)));
}

GameScene::~GameScene()
{
	CCLOG("Unregister all event listener...");
	getSmartFox()->RemoveEventListener(SFSEvent::PING_PONG, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnPingPong, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::USER_VARIABLES_UPDATE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnUserVarsUpdate, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::PROXIMITY_LIST_UPDATE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnProximityListUpdate, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::EXTENSION_RESPONSE, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnExtensionResponse, (unsigned long long)this)));
}

void GameScene::scrollBackground(float scrollX, float scrollY)
{
	// TODO update this function later
	// GetComponent<Renderer>().material.mainTextureOffset = 
	//	new Vector2(GetComponent<Renderer>().material.mainTextureOffset.x + scrollX * paralax, 
	// GetComponent<Renderer>().material.mainTextureOffset.y + scrollY * paralax);
}

bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!BaseScene::init())
	{
		return false;
	}	

#ifdef SHOW_BUTTONS
	isLeftBtnPressed = isRightBtnPressed = isThrustBtnPressed = isFireBtnPressed = 
	lastThrustBtnPressed = lastFireBtnPressed = false;
#else
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif // SHOW_BUTTONS
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 size = Director::getInstance()->getWinSize();

	rootNode = Node::create();
	addChild(rootNode);
	rootNode->setPosition(size / 2);

	background = Sprite::create("bg_starfield1.jpg");
	foreground = Sprite::create("bg_starfield2.png");
	rootNode->addChild(background);
	rootNode->addChild(foreground);
	Texture2D::TexParams ccTexParams[] = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	background->getTexture()->setTexParameters(ccTexParams);
	foreground->getTexture()->setTexParameters(ccTexParams);

	this->myStarship = NULL;
	this->starships = boost::shared_ptr<std::map<long int, StarshipNode*>>(new std::map<long int, StarshipNode*>());
	this->weaponShots = boost::shared_ptr<std::map<long int, WeaponShot*>>(new std::map<long int, WeaponShot*>());
	
	if (!AnimationCache::getInstance()->getAnimation("exp"))
	{
		char* str = new char[100];
		Vector<SpriteFrame*> animFrames(11);
		for (int i = 1; i < 12; i++)
		{
			if (i < 10) sprintf(str, "explosion_000%d.png", i);
			else sprintf(str, "explosion_00%d.png", i);
			animFrames.pushBack(Sprite::create(str)->getSpriteFrame());
		}
		delete[]str;
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.45f / 11);
		AnimationCache::getInstance()->addAnimation(animation, "exp");
	}

#ifndef SHOW_BUTTONS
	isThrustKeyDown = false;
	isFire1KeyDown = false;
#else
	// Left Btn
	leftBtn = cocos2d::ui::Button::create("Left_Button_Normal.png", "Left_Button_Pressed.png", "Left_Button_Pressed.png");
	leftBtn->setTitleText("");
	leftBtn->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
	leftBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			isLeftBtnPressed = true;
			break;
		case ui::Widget::TouchEventType::ENDED:
		case ui::Widget::TouchEventType::CANCELED:
			isLeftBtnPressed = false;
			break;
		}
	});
	leftBtn->setPosition(Vec2(149, 150));
	addChild(leftBtn);

	// Right Btn
	rightBtn = cocos2d::ui::Button::create("Left_Button_Normal.png", "Left_Button_Pressed.png", "Left_Button_Pressed.png");
	rightBtn->setTitleText("");
	rightBtn->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
	rightBtn->setFlippedX(true);
	rightBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			isRightBtnPressed = true;
			break;
		case ui::Widget::TouchEventType::ENDED:
		case ui::Widget::TouchEventType::CANCELED:
			isRightBtnPressed = false;
			break;
		}
	});
	rightBtn->setPosition(Vec2(151, 150));
	addChild(rightBtn);

	// Thrust
	thrustBtn = cocos2d::ui::Button::create("Thrust_Button_Normal.png", "Thrust_Button_Pressed.png", "Thrust_Button_Pressed.png");
	thrustBtn->setTitleText("");
	thrustBtn->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
	thrustBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			isThrustBtnPressed = true;
			lastThrustBtnPressed = false;
			break;
		case ui::Widget::TouchEventType::ENDED:
		case ui::Widget::TouchEventType::CANCELED:
			isThrustBtnPressed = false;
			lastThrustBtnPressed = true;
			break;
		}
	});
	thrustBtn->setPosition(Vec2(size.x - 150, 150));
	addChild(thrustBtn);

	// Fire
	fireBtn = cocos2d::ui::Button::create("Fire_Button_Normal.png", "Fire_Button_Pressed.png", "Fire_Button_Pressed.png");
	fireBtn->setTitleText("");
	fireBtn->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
	fireBtn->setFlippedX(true);
	fireBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			isFireBtnPressed = true;
			lastFireBtnPressed = false;
			break;
		case ui::Widget::TouchEventType::ENDED:
		case ui::Widget::TouchEventType::CANCELED:
			isFireBtnPressed = false;
			lastFireBtnPressed = true;
			break;
		}
	});
	fireBtn->setPosition(Vec2(size.x - 150, 150));
	addChild(fireBtn);
#endif // !SHOW_BUTTONS

	offsetX = offsetY = 0;
	return true;
}

void GameScene::updateShipDir(int dir, int direction)
{
	setStarshipRotating(myStarship->ship->id, direction);

	CCLOG("SEND request to server: %s", REQ_ROTATE.c_str());
	// Fire event to send a request to the server
	boost::shared_ptr<ISFSObject> paramsDir = boost::shared_ptr<ISFSObject>(new SFSObject());
	paramsDir->PutInt("dir", myStarship->ship->rotatingDir);
	boost::shared_ptr<SmartFox> sfs = getSmartFox();
	boost::shared_ptr<ExtensionRequest> request(new ExtensionRequest(REQ_ROTATE, paramsDir, sfs->LastJoinedRoom()));
	sfs->Send(request);
}

void GameScene::updateShipThrust(bool active)
{
	CCLOG("------------------- SENT THRUST EVENT");

	// Thrust activation is made of 3 steps:
	// 1) on key down the ship shows a small flame; no actual force is applied to the ship (no trajectory change)
	// 2) request is sent to the server which activates the thrust and sends a position reset event
	// 3) when the event is received the ship shows a bigger flame and the thrust force is applied during the simulation
	myStarship->ship->thrusterValue = 1;
	//myStarship.doThrust = true;

	boost::shared_ptr<ISFSObject> paramsThrust = boost::shared_ptr<ISFSObject>(new SFSObject());
	paramsThrust->PutBool("go", active);
	boost::shared_ptr<SmartFox> sfs = getSmartFox();
	boost::shared_ptr<ExtensionRequest> request(new ExtensionRequest(REQ_THRUST, paramsThrust, sfs->LastJoinedRoom()));
	sfs->Send(request);
}

void GameScene::fire()
{
	boost::shared_ptr<ISFSObject> paramsFire = boost::shared_ptr<ISFSObject>(new SFSObject());
	paramsFire->PutInt("wnum", 1);
	boost::shared_ptr<SmartFox> sfs = getSmartFox();
	boost::shared_ptr<ExtensionRequest> request(new ExtensionRequest(REQ_FIRE, paramsFire, sfs->LastJoinedRoom()));
	sfs->Send(request);
}

#ifndef SHOW_BUTTONS
// Implementation of the keyboard event callback function prototype
void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	if (myStarship == NULL) return;
	CCLOG("Have starship");
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		CCLOG("Rotating ship");
		int dir = (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ? -1 : 1);
		if (dir != myStarship->ship->rotatingDir) updateShipDir(dir, dir);
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		CCLOG("Key up pressed");
		if (!isThrustKeyDown) {
			isThrustKeyDown = true;
			CCLOG("Thurst...");

			updateShipThrust(true);
		}
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
		CCLOG("Key space pressed");
		if (!isFire1KeyDown)
		{
			CCLOG("Fire...");
			isFire1KeyDown = true;
			fire();
		}
	}
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	CCLOG("Key with keycode %d released", keyCode);
	if (myStarship == NULL) return;
	CCLOG("Have starship");
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		int dir = keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ? -1 : 1;
		if (dir == myStarship->ship->rotatingDir) updateShipDir(dir, 0);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (isThrustKeyDown)
		{
			isThrustKeyDown = false;
			CCLOG("Thurst...");

			updateShipThrust(false);
		}
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		CCLOG("Fire...");
		isFire1KeyDown = false;
	}
}
#endif

void GameScene::setup(boost::shared_ptr<ISFSObject> starsShipModels, boost::shared_ptr<ISFSObject> weaponsModels)
{
	this->starsShipModels = starsShipModels;
	this->weaponsShipModels = weaponsModels;
}

void GameScene::update(float deltaTime)
{
	BaseScene::update(deltaTime);
	gameTime += deltaTime;
	if (starships != NULL)
	{
		for (std::map<long, StarshipNode*>::iterator it = starships->begin(); it != starships->end(); ++it) {
			updateShip(it->second);
			it->second->update(deltaTime);
		}

		for (std::map<long, WeaponShot*>::iterator it = weaponShots->begin(); it != weaponShots->end(); ++it) {
			updateShot(it->second);
			it->second->update(deltaTime);
		}
	}

#ifdef SHOW_BUTTONS
	if (myStarship == NULL) return;

	// Dir
	int dir = 0;	
	if (isLeftBtnPressed) dir -= 1;
	if (isRightBtnPressed) dir += 1;
	if (dir != myStarship->ship->rotatingDir) updateShipDir(dir, dir);

	// Thrust	
	if (isThrustBtnPressed != lastThrustBtnPressed) 
	{
		updateShipThrust(isThrustBtnPressed);		
		isThrustBtnPressed = lastThrustBtnPressed;
	}
	
	// Fire	
	if (isFireBtnPressed != lastFireBtnPressed)
	{
		if (isFireBtnPressed) fire();
		isFireBtnPressed = lastFireBtnPressed;
	}
#endif // SHOW_BUTTONS
}

void GameScene::setStarshipRotating(long int id, long r)
{
	if (!starships->count(id)) return;
	StarshipNode* ship = starships->at(id);
	ship->ship->rotatingDir = r;
}

void GameScene::createStarship(long int userId, std::string userName, bool isMine, std::string type)
{
	if (starships->count(userId)) return;
	Starship* ship = Starship::createShip(type);
	StarshipNode* shipNode = StarshipNode::create(ship);
	shipNode->setupUserName(userName);
	rootNode->addChild(shipNode);

	ship->id = userId;
	ship->userName = userName;
	ship->settings = starsShipModels->GetSFSObject(type);

	// Add starship to array container
	starships->insert(std::pair<long int, StarshipNode*>(userId, shipNode));

	if (isMine)
	{
		myStarship = shipNode;
		myStarship->ship->isMine = true;
	}
}

void GameScene::createWeaponShot(long int id, std::string type, float x, float y, float vx, float vy, int elapsed)
{
	if (weaponShots->count(id)) return;
	WeaponShot* shot = WeaponShot::createBullet();
	rootNode->addChild(shot);
	shot->id = id;
	shot->settings = weaponsShipModels->GetSFSObject(type);

	// Add weapon shot to array container
	weaponShots->insert(std::pair<long int, WeaponShot*>(id, shot));

	// Set position and velocity
	shot->xx = x;
	shot->yy = y;
	shot->velocity.x = vx;
	shot->velocity.y = vy;
	shot->deltaTime = gameTime - elapsed / 1000.0f;
}

void GameScene::setStarshipPosition(long int userId, float x, float y, float vx, float vy, float d, bool t, int elapsed)
{
	if (starships->count(userId))
	{
		StarshipNode* shipNode = starships->at(userId);
		Starship* ship = shipNode->ship;

		// Set position and velocity
		ship->xx = x;
		ship->yy = y;
		ship->velocity.x = vx;
		ship->velocity.y = vy;
		ship->deltaTime = gameTime - elapsed / 1000.0f;

		// Set thruster
		ship->doThrust(t);

		// Set rotation angle
		ship->setRotation(CC_RADIANS_TO_DEGREES(d));

		// Render the starship
		// This simulates the starship movement taking into account the elapsed time since the server sent the new position/speed
		// and places the starship in the current coordinates
		updateShip(shipNode);
	}
}

void GameScene::updateShip(StarshipNode* shipNode)
{
	Starship* ship = shipNode->ship;
	int elapsed = (int)((gameTime - shipNode->ship->deltaTime) * 1000.0f);

	for (int i = 0; i < elapsed; i++)
	{
		// Ship rotation
		ship->setRotation(ship->getRotation() + CC_RADIANS_TO_DEGREES(ship->rotatingDir * ship->rotationSpeed()));

		// Thruster force
		if (ship->_doThrust)
		{
			ship->velocity.x += cos(CC_DEGREES_TO_RADIANS(ship->getRotation())) * ship->thrustAcceleration();
			ship->velocity.y += sin(CC_DEGREES_TO_RADIANS(ship->getRotation())) * ship->thrustAcceleration();
		}

		// Limit speed
		ship->normalizedSpeed();
		// Update ship position due to the calculated velocity
		ship->xx += ship->velocity.x;
		ship->yy += ship->velocity.y;
	}

	Vec2 shipLastPos = shipNode->getPosition();
	shipLastPos.y *= -1;
	shipNode->setPosition(Vec2(ship->xx, -ship->yy));

	ship->deltaTime = gameTime;

	if (ship->isMine)
	{
		// CCLOG("My Pos: %4.2f, %4.2f", ship->xx, ship->yy);
		Vec2 lastPos = rootNode->getPosition();
		Vec2 size = Director::getInstance()->getWinSize();
		rootNode->setPosition(size / 2 - Vec2(ship->xx, -ship->yy));
		background->setPosition(Vec2(ship->xx, -ship->yy));
		foreground->setPosition(Vec2(ship->xx, -ship->yy));

		offsetX += (ship->xx - shipLastPos.x);
		offsetY += (ship->yy - shipLastPos.y);
		background->setTextureRect(Rect(offsetX, offsetY, background->getContentSize().width, background->getContentSize().height));
		foreground->setTextureRect(Rect(offsetX, offsetY, foreground->getContentSize().width, foreground->getContentSize().height));
	}
}

void GameScene::updateShot(WeaponShot* shot)
{
	// Update shot position due to the calculated velocity
	shot->xx += shot->velocity.x;
	shot->yy += shot->velocity.y;


	int elapsed = (int)((gameTime - shot->deltaTime) * 1000.0f);

	for (int i = 0; i < elapsed; i++)
	{
		shot->xx += shot->velocity.x;
		shot->yy += shot->velocity.y;
	}

	shot->setPosition(Vec2(shot->xx, -shot->yy));
	shot->deltaTime = gameTime;
}

void GameScene::removeStarship(long int userId)
{
	if (!starships->count(userId)) return;
	StarshipNode* ship = starships->at(userId);
	starships->erase(userId);
	ship->runAction(Sequence::createWithTwoActions(FadeOut::create(0.5f), RemoveSelf::create()));

	if (ship == myStarship)
		myStarship = NULL;
}

void GameScene::removeWeaponShot(long int weaponId)
{
	if (!weaponShots->count(weaponId)) return;
	WeaponShot* shot = weaponShots->at(weaponId);

	// The shot could have already been removed if the explosion was notified by the server before the proximity update
	if (shot != NULL)
	{
		weaponShots->erase(weaponId);
	}
}

void GameScene::explodeWeaponShot(long int shotId, long int posX, long int posY)
{
	if (!weaponShots->count(shotId)) return;
	WeaponShot* shot = weaponShots->at(shotId);

	// The shot could have already been removed if the proximity update was notified before the explosion
	if (shot != NULL)
	{
		// Remove shot
		removeWeaponShot(shotId);
		shot->explode(posX, posY);
	}
}

void OnPingPong(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	int* value = (int*)evt->Params()->at("lagValue").get();
	GameScene* scene = (GameScene*)context;
	scene->m_clientServerLag = (*value) / 2;
}

int contain(boost::shared_ptr<std::vector<std::string>> changedVars, std::string val) {
	for (int i = 0; i < changedVars->size(); i++) {
		if (!strcmp(changedVars->at(i).c_str(), val.c_str())) return i;
	}
	return -1;
}

void OnUserVarsUpdate(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	CCLOG("OnUserVarsUpdate: ");

	GameScene* scene = (GameScene*)context;

	boost::shared_ptr<User> user = ((boost::static_pointer_cast<User>))(evt->Params()->at("user"));
	boost::shared_ptr<void> userVars = evt->Params()->at("changedVars");
	boost::shared_ptr<std::vector<std::string>> changedVars = ((boost::static_pointer_cast<std::vector<std::string>>))(userVars);
	if (contain(changedVars, UV_ROTATE) >= 0)
	{
		// Make user starship start or stop rotating (excluding current user who controls his starship directly)
		if (user != scene->getSmartFox()->MySelf())
		{
			boost::shared_ptr<long> r1 = user->GetVariable(UV_ROTATE)->GetIntValue();
			scene->setStarshipRotating(user->Id(), *r1.get());
			CCLOG("-- OnUserVarsUpdate: Set starship rotation: %ld", *r1.get());
		}
	}

	if (contain(changedVars, UV_X) >= 0 || contain(changedVars, UV_Y) >= 0 ||
		contain(changedVars, UV_VX) >= 0 || contain(changedVars, UV_VY) >= 0 ||
		contain(changedVars, UV_DIR) >= 0 || contain(changedVars, UV_THRUST) >= 0)
	{
		bool myShipJustCreated = false;
		// Create current user starship if not yet existing
		// For debug purposes, if the AoI is smaller than the viewport size, display it around the current user starship
		if (user == scene->getSmartFox()->MySelf())
		{
			scene->createStarship(user->Id(), *user->Name().get(), true, *user->GetVariable(UV_MODEL)->GetStringValue().get());
			myShipJustCreated = true;
			CCLOG("-- OnUserVarsUpdate: Create myself");
		}

		// Reset user starship state in simulator, taking lag into account
		float x = (float)*user->GetVariable(UV_X)->GetDoubleValue().get();
		float y = (float)*user->GetVariable(UV_Y)->GetDoubleValue().get();
		float vx = (float)*user->GetVariable(UV_VX)->GetDoubleValue().get();
		float vy = (float)*user->GetVariable(UV_VY)->GetDoubleValue().get();
		float d = (float)*user->GetVariable(UV_DIR)->GetDoubleValue().get();
		bool t = *user->GetVariable(UV_THRUST)->GetBoolValue().get();

		scene->setStarshipPosition(user->Id(), x, y, vx, vy, d, t, scene->m_clientServerLag);
		if (myShipJustCreated) {
			CCLOG("-- OnUserVarsUpdate: MyPos(%ld): (%4.2f, %4.2f)", user->Id(), x, y);
		}
		else {
			CCLOG("-- OnUserVarsUpdate: Ship(%ld) pos: (%4.2f, %4.2f)", user->Id(), x, y);
		}
	}
}

void OnProximityListUpdate(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	CCLOG("OnProximityListUpdate: ");

	GameScene* scene = (GameScene*)context;

	boost::shared_ptr<std::vector<boost::shared_ptr<User>>> removedUsers = ((boost::static_pointer_cast<std::vector<boost::shared_ptr<User>>>))(evt->Params()->at("removedUsers"));
	for (int i = 0; i < removedUsers->size(); i++)
	{
		scene->removeStarship(removedUsers->at(i)->Id());
	}

	// Loop the addedUsers list in the event params to create the starships now visible
	// To the usual lag we add 10ms, which is half the value of the proximityListUpdateMillis setting on the server
	// As we don't know exactly after how much time the update event was fired after the users updated their positions in the MMORoom
	// (could be 0ms up to 20ms), we use half the proximityListUpdateMillis value as a sort of mean value for an additional corretion of the lag
	boost::shared_ptr<std::vector<boost::shared_ptr<User>>> addedUsers = ((boost::static_pointer_cast<std::vector<boost::shared_ptr<User>>>))(evt->Params()->at("addedUsers"));
	for (int i = 0; i < addedUsers->size(); i++)
	{
		boost::shared_ptr<User> user = addedUsers->at(i);

		// Create starship
		scene->createStarship(user->Id(), *user->Name().get(), false, *user->GetVariable(UV_MODEL)->GetStringValue().get());

		// Get position-related User Variables
		float x = (float)*user->GetVariable(UV_X)->GetDoubleValue().get();
		float y = (float)*user->GetVariable(UV_Y)->GetDoubleValue().get();
		float vx = (float)*user->GetVariable(UV_VX)->GetDoubleValue().get();
		float vy = (float)*user->GetVariable(UV_VY)->GetDoubleValue().get();
		float d = (float)*user->GetVariable(UV_DIR)->GetDoubleValue().get();
		bool t = *user->GetVariable(UV_THRUST)->GetBoolValue().get();
		int r = *user->GetVariable(UV_ROTATE)->GetIntValue().get();

		// Set starship rotating flag
		scene->setStarshipRotating(user->Id(), r);

		// Set starship position
		scene->setStarshipPosition(user->Id(), x, y, vx, vy, d, t, scene->m_clientServerLag + 10);
	}

	// Loop the removedItems list in the event params to remove the weapon shots no more visible
	// NOTE: sprites might have been already removed in case the shots explode within the AoI of the user
	// (notified by a dedicated Extension response) 
	boost::shared_ptr<std::vector<boost::shared_ptr<IMMOItem>>> removedItems = ((boost::static_pointer_cast<std::vector<boost::shared_ptr<IMMOItem>>>))(evt->Params()->at("removedItems"));
	for (int i = 0; i < removedItems->size(); i++)
	{
		scene->removeWeaponShot(removedItems->at(i)->Id());
	}

	// Loop the addedItems list in the event params to create those now visible
	// The same note about addedUsers applies here
	boost::shared_ptr<std::vector<boost::shared_ptr<IMMOItem>>> addedItems = ((boost::static_pointer_cast<std::vector<boost::shared_ptr<IMMOItem>>>))(evt->Params()->at("addedItems"));
	for (int i = 0; i < addedItems->size(); i++)
	{
		boost::shared_ptr<IMMOItem> item = addedItems->at(i);

		boost::shared_ptr<std::string> type = item->GetVariable(IV_TYPE)->GetStringValue();
		if (!strcmp(type->c_str(), ITYPE_WEAPON.c_str()))
		{
			// Get position-related MMOItem Variables
			boost::shared_ptr<std::string> im = item->GetVariable(IV_MODEL)->GetStringValue();
			float ix = (float)*item->GetVariable(IV_X)->GetDoubleValue().get();
			float iy = (float)*item->GetVariable(IV_Y)->GetDoubleValue().get();
			float ivx = (float)*item->GetVariable(IV_VX)->GetDoubleValue().get();
			float ivy = (float)*item->GetVariable(IV_VY)->GetDoubleValue().get();

			// Create weapon shot
			scene->createWeaponShot(item->Id(), *im.get(), ix, iy, ivx, ivy, scene->m_clientServerLag + 10);
		}
	}
}

void OnExtensionResponse(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	GameScene* scene = (GameScene*)context;

	boost::shared_ptr<ISFSObject> paramsExplode = ((boost::static_pointer_cast<ISFSObject>))(evt->Params()->at("params"));
	boost::shared_ptr<std::string> cmd = ((boost::static_pointer_cast<std::string>))(evt->Params()->at("cmd"));

	// A weapon shot exploded
	if (!strcmp(cmd->c_str(), RES_SHOT_XPLODE.c_str()))
	{
		long shotId = *paramsExplode->GetInt("id").get();
		long posX = *paramsExplode->GetInt("x").get();
		long posY = *paramsExplode->GetInt("y").get();
		scene->explodeWeaponShot(shotId, posX, posY);
	}
}