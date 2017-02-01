#ifndef __IEVENT_LISTENER_H__
#define __IEVENT_LISTENER_H__

#include <iostream>

class IEventListener
{
public:
	virtual void OnEvent(std::string, void* data) = 0;
};

#endif // !__IEVENT_LISTENER_H__