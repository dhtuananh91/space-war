#ifndef __SERVER_CONNECTOR_H__
#define __SERVER_CONNECTOR_H__

#include "SmartFox.h"
#include "Core/BaseEvent.h"
#include "Util/EventDispatcher.h"
#include "Requests/LoginRequest.h"
#include "Requests/LogoutRequest.h"
#include "Networks/IEventListener.h"

void OnSmartfoxLog(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnConnection(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnLogin(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnLoginError(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnLogout(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnConnectionLost(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnPingPong(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnRoomJoin(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnRoomJoinError(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnUserExitRoom(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnUserVarsUpdate(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnProximityListUpdate(unsigned long long context, boost::shared_ptr<BaseEvent> evt);
void OnExtensionResponse(unsigned long long context, boost::shared_ptr<BaseEvent> evt);

class AppDelegate;
class ServerConnector
{
	static ServerConnector* m_ptrInstance;
	ServerConnector(AppDelegate* appDelegate);
	virtual	~ServerConnector();
public:
	boost::shared_ptr<Sfs2X::SmartFox> getSmartFox();
	void setKey(std::string key, void* value);
	void* getKey(std::string key);

	void onConnected(boost::shared_ptr<BaseEvent> evt);	
	void onConnectionLost(boost::shared_ptr<BaseEvent> evt);
	void connect();
	bool isConnected() { return m_isConnected; }
	void cleanupSmartFox();
	void initSmartFox();
public:
	static ServerConnector* GetInstance();
	static void CreateInstance(AppDelegate* appDelegate);
	static void DestroyInstance();
	void update(float deltaTime);
private:
	boost::shared_ptr<Sfs2X::SmartFox> m_smartFoxServer;
	std::map<std::string, void*> m_data;
	AppDelegate* m_appDelegate;
	bool m_isConnected;
};

#endif // !__SERVER_CONNECTOR_H__