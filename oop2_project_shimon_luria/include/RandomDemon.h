#pragma once
#include "Demon.h"
//#include "Factory.h"
//class Factory;
class RandomDemon : public Demon
{
public:
	RandomDemon(int, int);
	virtual void back();
	virtual void setDirection(sf::Vector2f);

	//	static bool m_registerit;
};
