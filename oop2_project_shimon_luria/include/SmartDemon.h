#pragma once
#include "Demon.h"
//#include "Factory.h"
//class Factory;
class SmartDemon : public Demon
{
public:
	SmartDemon(int, int);
	virtual void back();
	virtual void setDirection(sf::Vector2f);

	//	static bool m_registerit;
};
