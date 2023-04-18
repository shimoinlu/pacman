#pragma once
#include "MoveObject.h"
#include "Shot.h"
//#include "Factory.h"
//class Factory;

class Demon : public MoveObject
{
public:
	Demon(int, int);
	virtual void mov();
	virtual void setDirection(sf::Vector2f);
	virtual void back();
	virtual void reset();
	virtual void animate(sf::Time);
	virtual std::string name() { return "Demon"; }
	std::unique_ptr<Shot> DemonShots();
protected:
	std::vector<sf::Sprite> m_animate_pic_right;
	std::vector<sf::Sprite> m_animate_pic_left;

	//	static bool m_registerit;
};
