#include "LoginScene.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "ShipScene.h"
#include "../ServerConnector.h"
#include "ui/UIScale9Sprite.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

NewSceneData LoginScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LoginScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return NewSceneData(scene, layer);
}

void LoginScene::setAppDelegate(AppDelegate * appDelegate)
{
	BaseScene::setAppDelegate(appDelegate);

	getSmartFox()->AddEventListener(SFSEvent::LOGIN, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLogin, (unsigned long long)this)));
	getSmartFox()->AddEventListener(SFSEvent::LOGIN_ERROR, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLoginError, (unsigned long long)this)));
}

LoginScene::~LoginScene()
{
	getSmartFox()->RemoveEventListener(SFSEvent::LOGIN, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLogin, (unsigned long long)this)));
	getSmartFox()->RemoveEventListener(SFSEvent::LOGIN_ERROR, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLoginError, (unsigned long long)this)));
}

// on "init" you need to initialize your instance
bool LoginScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!BaseScene::init())
    {
        return false;
    }
	m_userName = "";

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 size = Director::getInstance()->getWinSize();	

	Sprite *sprite = Sprite::create("bg_starfield1.jpg");
	addChild(sprite);
	sprite->setPosition(size / 2);

	Sprite *title = Sprite::create("title.png");
	addChild(title);
	title->setPosition(Vec2(size.x / 2, size.y - 150));

	Label* label = Label::createWithTTF("UserName:", "fonts/Akashi.ttf", 32);
	addChild(label);	
	label->setPosition(Vec2(size.x / 2 - 260, size.y - 300));

	ui::Scale9Sprite* inputBg = ui::Scale9Sprite::create(Rect(32, 10, 310, 20), "username_bg.png");
	addChild(inputBg);
	inputBg->setPosition(Vec2(size.x / 2, size.y - 350));
	inputBg->setContentSize(Size(700, 48));

	ui::TextField* textField = ui::TextField::create("Please input your username here...", "fonts/Akashi.ttf", 32);
	addChild(textField);
	textField->setPosition(Vec2(size.x / 2, size.y - 355));
	textField->setContentSize(Size(700, 48));
	textField->setTextHorizontalAlignment(TextHAlignment::LEFT);
	textField->addEventListener([&](Ref* sender, ui::TextField::EventType type) {
		switch (type)
		{
		case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME:
			break;
		case cocos2d::ui::TextField::EventType::DETACH_WITH_IME:
			this->m_userName = ((ui::TextField*)sender)->getString();
			CCLOG("Updated username: %s", this->m_userName.c_str());
			break;
		case cocos2d::ui::TextField::EventType::INSERT_TEXT:
			this->m_userName = ((ui::TextField*)sender)->getString();
			break;
		case cocos2d::ui::TextField::EventType::DELETE_BACKWARD:
			this->m_userName = ((ui::TextField*)sender)->getString();
			break;
		default:
			break;
		}
	});	
	
	ui::Button* button = ui::Button::create("button_play.png", "button_play.png", "button_play.png");
	button->setTitleText("");	
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:			
			CCLOG("Username: %s", m_userName.c_str());
			login(m_userName);
			break;
		default:
			break;
		}
	});
	button->setPosition(Vec2(size.x / 2 + 260, size.y - 420));
	addChild(button);

    return true;
}

void LoginScene::login(std::string username)
{
	if (ServerConnector::GetInstance()->isConnected()) {
		boost::shared_ptr<IRequest> request(new LoginRequest(username, "", "SpaceWar"));
		ServerConnector::GetInstance()->getSmartFox()->Send(request);
	}
}

void OnLogin(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	LoginScene *loginScene = (LoginScene *)context;
	AppDelegate* appDelegate = loginScene->getAppDelegate();
	boost::shared_ptr<Sfs2X::SmartFox> sfs = loginScene->getSmartFox();

	CCLOG("Enable lag monitor");
	sfs->EnableLagMonitor(true, 1, 5);

	CCLOG("Save username in case it was assigned by the server (guest login for example)");
	boost::shared_ptr<void> userPtr = evt->Params()->at("user");
	User* user = (User*)userPtr.get();
	ServerConnector::GetInstance()->setKey("userName", (void*)user->Name().get());

	boost::shared_ptr<void> dataPtr = evt->Params()->at("data");
	ISFSObject* data = (ISFSObject*)dataPtr.get();

	CCLOG("Retrieve starship models and weapon models from custom data sent by the Zone Extension");
	boost::shared_ptr<ISFSObject> starshipModels = data->GetSFSObject("starships");
	boost::shared_ptr<ISFSObject> weaponModels = data->GetSFSObject("weapons");

	loginScene->isStopUpdateMsg = true;
	cocos2d::Layer* layer = appDelegate->changeScene(SceneName::SN_Ship);
	ShipScene* shipScene = (ShipScene*)layer;
	if (shipScene) {
		shipScene->setup(starshipModels, weaponModels);
	}
}

void OnLoginError(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	CCLOG("On Login Error");
}