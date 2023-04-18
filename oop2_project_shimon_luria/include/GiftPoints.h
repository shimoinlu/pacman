#pragma once
#include "NonMoveObject.h"
//#include "Factory.h"
//class Factory;
class GiftPoints : public NonMoveObject
{
public:
	GiftPoints(int, int);
	static sf::Texture& getTexture();
	virtual std::string name() { return "GiftPoints"; }
	int f();
	//	static bool m_registerit;
};
