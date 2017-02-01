#include "ServerConnector.h"
#include "AppDelegate.h"

void OnSmartfoxLog(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	boost::shared_ptr<LoggerEvent> loggerEvent = ((boost::static_pointer_cast<LoggerEvent>))(evt);
	boost::shared_ptr<std::string> msg = ((boost::static_pointer_cast<std::string >))(loggerEvent->Params()->at("message"));
	CCLOG("SmartfoxLog: %s", msg->c_str());
}

void OnConnection(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	ServerConnector::GetInstance()->onConnected(evt);	
}

void OnConnectionLost(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	ServerConnector::GetInstance()->onConnectionLost(evt);
}

void OnLogout(unsigned long long context, boost::shared_ptr<BaseEvent> evt) {
	CCLOG("Logout done");
}

ServerConnector* ServerConnector::m_ptrInstance = NULL;
ServerConnector::ServerConnector(AppDelegate* appDelegate) : m_appDelegate(appDelegate), m_isConnected(false)
{	
	initSmartFox();
	connect();
}

ServerConnector::~ServerConnector()
{
	// Remove SFS2X event listeners
	m_smartFoxServer->RemoveEventListener(SFSEvent::CONNECTION, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnConnection, (unsigned long long)this)));
	m_smartFoxServer->RemoveEventListener(SFSEvent::CONNECTION_LOST, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnConnectionLost, (unsigned long long)this)));
	// m_smartFoxServer->RemoveEventListener(SFSEvent::LOGOUT, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLogout, (unsigned long long)this)));

	// Destroy SmartFox instance
	m_smartFoxServer->Disconnect();
	cleanupSmartFox();	
}

ServerConnector* ServerConnector::GetInstance()
{
	return m_ptrInstance;
}

void ServerConnector::CreateInstance(AppDelegate * appDelegate)
{
	CC_SAFE_DELETE(m_ptrInstance);
	m_ptrInstance = new ServerConnector(appDelegate);
}

void ServerConnector::DestroyInstance()
{
	CC_SAFE_DELETE(m_ptrInstance);
}

void ServerConnector::update(float deltaTime)
{
	m_smartFoxServer->ProcessEvents();
}

boost::shared_ptr<Sfs2X::SmartFox> ServerConnector::getSmartFox()
{
	return m_smartFoxServer;
}

void ServerConnector::setKey(std::string key, void* value) { m_data[key] = value; }

void* ServerConnector::getKey(std::string key) { return m_data[key]; }

void ServerConnector::cleanupSmartFox()
{
	m_smartFoxServer = NULL;
}

void ServerConnector::initSmartFox()
{
#ifdef _DEBUG
	m_smartFoxServer = boost::shared_ptr<Sfs2X::SmartFox>(new Sfs2X::SmartFox(true));
#else
	m_smartFoxServer = boost::shared_ptr<Sfs2X::SmartFox>(new Sfs2X::SmartFox(false));
#endif

	m_smartFoxServer->ThreadSafeMode(true);
//	m_smartFoxServer->AddLogListener(Sfs2X::Logging::LOGLEVEL_DEBUG, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnSmartfoxLog, (unsigned long long)this)));
//	m_smartFoxServer->AddLogListener(Sfs2X::Logging::LOGLEVEL_ERROR, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnSmartfoxLog, (unsigned long long)this)));
//	m_smartFoxServer->AddLogListener(Sfs2X::Logging::LOGLEVEL_INFO, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnSmartfoxLog, (unsigned long long)this)));
//	m_smartFoxServer->AddLogListener(Sfs2X::Logging::LOGLEVEL_WARN, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnSmartfoxLog, (unsigned long long)this)));
	
	// Add some basic events callback
	m_smartFoxServer->AddEventListener(SFSEvent::CONNECTION, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnConnection, (unsigned long long)this)));
	m_smartFoxServer->AddEventListener(SFSEvent::CONNECTION_LOST, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnConnectionLost, (unsigned long long)this)));
	// m_smartFoxServer->AddEventListener(SFSEvent::LOGOUT, boost::shared_ptr<EventListenerDelegate>(new EventListenerDelegate(OnLogout, (unsigned long long)this)));

	// srand(time(NULL));
	// int userId = rand() % 1000 + 1;
	// m_userName = new char[4];
	// sprintf(m_userName, "%d", userId);
}

void ServerConnector::connect()
{
	m_smartFoxServer->Connect("188.166.241.148", 9933);
}

void ServerConnector::onConnected(boost::shared_ptr<BaseEvent> evt)
{
	// Get connection result
	boost::shared_ptr<map<string, boost::shared_ptr<void> > > ptrEventParams = evt->Params();
	boost::shared_ptr<void> ptrEventParamValueSuccess = (*ptrEventParams)["success"];
	boost::shared_ptr<bool> ptrErrorMessage = ((boost::static_pointer_cast<bool>))(ptrEventParamValueSuccess);

	if (*ptrErrorMessage)
	{
		// Connection established
		CCLOG("Connection established and handshake completed with success");

		m_isConnected = true;
	}
	else
	{
		CCLOG("Reconnect here");
		cleanupSmartFox();
		initSmartFox();
		connect();
	}	
}

void ServerConnector::onConnectionLost(boost::shared_ptr<BaseEvent> evt)
{
	cleanupSmartFox();
	initSmartFox();
	connect();
	m_appDelegate->changeScene(SceneName::SN_Login);
}
