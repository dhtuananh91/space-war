#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include <iostream>
#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Util/EventDispatcher.h"
#include "Requests/LoginRequest.h"
#include "Requests/LogoutRequest.h"

#include "Scenes/SceneName.h"

using namespace Sfs2X;

/**
@brief    The cocos2d Application.

Private inheritance here hides part of interface from Director.
*/
class  AppDelegate : private cocos2d::Application
{
private:
	boost::shared_ptr<Sfs2X::SmartFox> m_smartFoxServer;
	char* m_userName;
	SceneName m_currentScene;
	cocos2d::Layer* m_currentLayer;
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  Called when the application moves to the background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  Called when the application reenters the foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
	
	cocos2d::Layer* changeScene(SceneName newScene);

	SceneName getCurrentSceneName() { return m_currentScene; }

	cocos2d::Layer* getCurrentLayer() { return m_currentLayer; }
};

#endif // _APP_DELEGATE_H_