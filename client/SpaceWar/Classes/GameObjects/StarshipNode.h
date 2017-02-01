#ifndef __STAR_SHIP_NODE_H__
#define __STAR_SHIP_NODE_H__

#include <cocos2d.h>

class Starship;
class StarshipNode : public cocos2d::Node
{
public:
	Starship* ship;
	cocos2d::Label* nameLbl;
	cocos2d::Label* positionLbl;
protected:
	char* positionStr;
public:
	static StarshipNode* create(Starship* ship);
	StarshipNode();
	virtual bool init(Starship* starship);
	virtual ~StarshipNode();
	void setupUserName(std::string name);
	char* getPositionStr();
	void update(float deltaTime);
};

#endif // !__STAR_SHIP_NODE_H__