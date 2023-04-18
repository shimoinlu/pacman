#pragma once
#include "SmartDemon.h"
#include <cmath>
//#include <r>
//#include "Factory.h"
SmartDemon::SmartDemon(int r, int c)
	:Demon(r, c)
{
}
void SmartDemon::back()
{
	Demon::back();
}
void SmartDemon::setDirection(sf::Vector2f pacLocation)
{
	if (std::abs(pacLocation.x - m_faceObject.getPosition().x) > std::abs(pacLocation.y - m_faceObject.getPosition().y))
		if (pacLocation.x > m_faceObject.getPosition().x)
			m_dir = Direction(0,0, 1, 0);
		else
			m_dir = Direction(0,0, 0, 1);
	else
		if (pacLocation.y > m_faceObject.getPosition().y)
			m_dir = Direction(0, 1, 0, 0);
		else
			m_dir = Direction(1, 0, 0, 0);

}
//bool SmartDemon::m_registerit = Factory::registerit("SmartDemon", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<SmartDemon>(r, c); });
