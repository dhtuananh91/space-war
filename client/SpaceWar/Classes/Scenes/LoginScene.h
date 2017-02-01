#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__

#include "cocos2d.h"
#include <iostream>
#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Util/EventDispatcher.h"
#include "Requests/LoginRequest.h"
#include "Requests/LogoutRequest.h"

#include "SceneName.h"
#include "NewSceneData.h"
#include "BaseScene.h"

class AppDelegate;
class LoginScene : public BaseScene
{
	std::string m_userName;
public:
    static NewSceneData createScene();

	virtual ~LoginScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(LoginScene);

	virtual void setAppDelegate(AppDelegate* appDelegate);
	void login(std::string username);
};

#endif // __LOGIN_SCENE_H__
