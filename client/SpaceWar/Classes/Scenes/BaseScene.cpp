#include "BaseScene.h"
#include "AppDelegate.h"
#include "../ServerConnector.h"

BaseScene::BaseScene()
{	
	isStopUpdateMsg = false;
}

BaseScene::~BaseScene()
{
}

bool BaseScene::init()
{
	bool result = Layer::init();
	scheduleUpdate();
	return result;
}

void BaseScene::update(float deltaTime)
{
	if (!isStopUpdateMsg)
		ServerConnector::GetInstance()->update(deltaTime);
}

void BaseScene::setAppDelegate(AppDelegate * appDelegate)
{
	m_appDelegate = appDelegate;
}

boost::shared_ptr<Sfs2X::SmartFox> BaseScene::getSmartFox()
{
	return ServerConnector::GetInstance()->getSmartFox();
}