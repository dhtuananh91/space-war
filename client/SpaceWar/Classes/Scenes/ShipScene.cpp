#include "ShipScene.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "GameScene.h"
#include "../ServerConnector.h"

USING_NS_CC;

NewSceneData ShipScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ShipScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return NewSceneData(scene, layer);
}

void ShipScene::setAppDelegate(AppDelegate * appDelegate)
{
	BaseScene::setAppDelegate(appDelegate);

	getSmartFox()->AddEventListener(SFSEvent::ROOM_JOIN, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnRoomJoin, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::ROOM_JOIN_ERROR, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnRoomJoinError, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::USER_EXIT_ROOM, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnUserExitRoom, (unsigned long long)this)));
}

ShipScene::~ShipScene()
{
	getSmartFox()->RemoveEventListener(SFSEvent::ROOM_JOIN, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnRoomJoin, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::ROOM_JOIN_ERROR, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnRoomJoinError, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::USER_EXIT_ROOM, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnUserExitRoom, (unsigned long long)this)));
}

// on "init" you need to initialize your instance
bool ShipScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!BaseScene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 size = Director::getInstance()->getWinSize();

	Sprite *sprite = Sprite::create("bg_starfield1.jpg");
	addChild(sprite);
	sprite->setPosition(size / 2);

	Sprite *title = Sprite::create("title.png");
	addChild(title);
	title->setPosition(Vec2(size.x / 2, size.y - 150));	

	m_title = Label::create("Please choose your ship", "fonts/Akashi.ttf", 32);
	m_title->setHorizontalAlignment(TextHAlignment::LEFT);
	addChild(m_title);
	m_title->setPosition(size.x / 2 - 200, size.y - 300);

	m_menu = Menu::create();
	addChild(m_menu);
	m_menu->setPosition(size.x / 2, size.y - 480);

	return true;
}

void ShipScene::setup(boost::shared_ptr<ISFSObject> starsShipModels, boost::shared_ptr<ISFSObject> weaponsModels)
{
	m_starsShipModels = boost::shared_ptr<ISFSObject>(starsShipModels);
	m_weaponsShipModels = boost::shared_ptr<ISFSObject>(weaponsModels);

	boost::shared_ptr<std::vector<std::string>> keys = m_starsShipModels->GetKeys();
	float width = 0;
	for (int i = 0; i < keys->size(); i++)
	{
		MenuItemImage* sprite = NULL;
		MenuItemLabel* label = NULL;
		boost::shared_ptr<ISFSObject> starShip = m_starsShipModels->GetSFSObject(keys->at(i));
		boost::shared_ptr<std::string> modelName = starShip->GetUtfString("model");
		if (!strcmp(modelName->c_str(), "Astro")) {
			sprite = MenuItemImage::create("ship_menu_astro.png", "ship_menu_astro.png", CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
			label = MenuItemLabel::create(Label::create(modelName->c_str(), "fonts/Akashi.ttf", 24), CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
		}
		else if (!strcmp(modelName->c_str(), "Viking")) {
			sprite = MenuItemImage::create("ship_menu_viking.png", "ship_menu_viking.png", CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
			label = MenuItemLabel::create(Label::create(modelName->c_str(), "fonts/Akashi.ttf", 24), CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
		}
		else if (!strcmp(modelName->c_str(), "Raptor")) {
			sprite = MenuItemImage::create("ship_menu_raptor.png", "ship_menu_raptor.png", CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
			label = MenuItemLabel::create(Label::create(modelName->c_str(), "fonts/Akashi.ttf", 24), CC_CALLBACK_0(ShipScene::onMenuClicked, this, i));
		}
		else {
			// It's a bug
		}
		if (sprite) {
			sprite->setTag(i * 1000);
			label->setTag(i * 1000);

			m_shipModels.push_back(sprite);
			m_shipNames.push_back(label);
			m_menu->addChild(sprite);
			m_menu->addChild(label);
			width += sprite->getContentSize().width;
		}
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 size = Director::getInstance()->getWinSize();

	if (m_shipModels.size() > 0) {
		float sceneWidth = Director::getInstance()->getWinSize().width;
		float sceneHeight = Director::getInstance()->getWinSize().height;
		float scale = sceneWidth / width;

		float offSet = 0;
		for (int i = 0; i < m_shipModels.size(); i++)
		{
			MenuItemImage* sprite = m_shipModels[i];			
			sprite->setScale(scale);
			sprite->setPosition(-sceneWidth * 0.5f + offSet + sprite->getContentSize().width * scale * 0.5f, 0);
			offSet += sprite->getContentSize().width * scale;
			MenuItemLabel* label = m_shipNames[i];
			label->setPosition(sprite->getPositionX(), -200);
		}
		m_menu->setScale(0.9f);
	}
}

void ShipScene::onMenuClicked(int index)
{	
	boost::shared_ptr<std::vector<std::string>> keys = m_starsShipModels->GetKeys();
	boost::shared_ptr<ISFSObject> starShip = m_starsShipModels->GetSFSObject(keys->at(index));
	boost::shared_ptr<std::string> modelName = starShip->GetUtfString("model");
	boost::shared_ptr<UserVariable> shipModelUV = boost::shared_ptr<UserVariable>(new SFSUserVariable("sModel", modelName));

	boost::shared_ptr<std::vector<boost::shared_ptr<UserVariable>>> userVars = boost::shared_ptr<std::vector<boost::shared_ptr<UserVariable>>>(
		new std::vector<boost::shared_ptr<UserVariable>>);
	userVars->push_back(shipModelUV);
	boost::shared_ptr<Sfs2X::SmartFox> sfs = getSmartFox();
	boost::shared_ptr<SetUserVariablesRequest> request = boost::shared_ptr<SetUserVariablesRequest>(new SetUserVariablesRequest(userVars));
	sfs->Send(request);

	boost::shared_ptr<std::vector<boost::shared_ptr<Room>>> rooms = sfs->RoomList();
	for (int i = 0; i < rooms->size(); i++)
	{
		boost::shared_ptr<Room> room = rooms->at(i);
		if (room->UserCount() < room->MaxUsers()) {
			boost::shared_ptr<JoinRoomRequest> request = boost::shared_ptr<JoinRoomRequest>(new JoinRoomRequest(room->Id()));
			sfs->Send(request);
		}
	}
}

void OnRoomJoin(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	CCLOG("On Room Joined");
	
	ShipScene* scene = (ShipScene*)context;
	scene->isStopUpdateMsg = true;
	Layer* layer = scene->getAppDelegate()->changeScene(SceneName::SN_Game);
	GameScene* gameScene = (GameScene*)layer;
	if (gameScene) {
		gameScene->setup(scene->m_starsShipModels, scene->m_weaponsShipModels);
	}
}

void OnRoomJoinError(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	string* str = (string*)evt->Params()->at("errorMessage").get();
	CCLOG("Display error in solar system selection screen %s", str->c_str());
}

void OnUserExitRoom(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {

}