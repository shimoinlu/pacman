#pragma once
#include "MoveObject.h"
 
class Shot :public MoveObject
{
public:
	Shot(sf::Vector2f,Direction);
	virtual void mov();
	virtual void back();
	virtual void animate(sf::Time);

protected:
	std::vector<sf::Sprite> m_animate_pic;

};