#include "StarshipNode.h"
#include "Starship.h"

StarshipNode* StarshipNode::create(Starship* ship) {
	StarshipNode *node = new (std::nothrow) StarshipNode();
	if (node && node->init(ship))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

StarshipNode::StarshipNode()
{
	nameLbl = NULL;
	positionLbl = NULL;
	ship = NULL;
	positionStr = new char[64];
}

StarshipNode::~StarshipNode()
{
	CC_SAFE_DELETE_ARRAY(positionStr);
}

bool StarshipNode::init(Starship* starship)
{
	if (Node::init()) {
		ship = starship;
		addChild(ship);

		positionLbl = cocos2d::Label::create(getPositionStr(), "fonts/Akashi.ttf", 12);
		addChild(positionLbl);
		positionLbl->setPosition(cocos2d::Vec2(0, -24));

		return true;
	}
	return false;
}

void StarshipNode::setupUserName(std::string name)
{
	if (!nameLbl)
	{
		nameLbl = cocos2d::Label::create(name, "fonts/Akashi.ttf", 12);
		addChild(nameLbl);
		nameLbl->setPosition(cocos2d::Vec2(0, 20));
	}
	else nameLbl->setString(name);
}

char* StarshipNode::getPositionStr()
{
	sprintf(positionStr, "(%d, %d)", (int)ship->xx, (int)ship->yy);
	return positionStr;
}

void StarshipNode::update(float deltaTime)
{
	positionLbl->setString(getPositionStr());
}