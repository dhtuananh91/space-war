#ifndef __BASE_SCENE_H__
#define __BASE_SCENE_H__

#include <cocos2d.h>
#include "SmartFox.h"

class AppDelegate;
class BaseScene : public cocos2d::Layer
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual bool init();
	virtual void update(float deltaTime);
	virtual void setAppDelegate(AppDelegate* appDelegate);
	virtual AppDelegate* getAppDelegate() { return m_appDelegate; }
	virtual boost::shared_ptr<Sfs2X::SmartFox> getSmartFox();
protected:
	AppDelegate* m_appDelegate;
public:
	bool isStopUpdateMsg;
};

#endif // !__BASE_SCENE_H__