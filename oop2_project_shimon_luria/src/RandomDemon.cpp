#pragma once
#include "RandomDemon.h"
//#include <r>
//#include "Factory.h"
RandomDemon::RandomDemon(int r, int c)
	:Demon(r, c)
{
	int dir = rand() % 2;
	switch (++dir)
	{
	case 1:
		m_dir = Direction(1, 0, 0, 0);
		break;
	case 2:
		m_dir = Direction(0, 0, 1, 0);
		break;
	default:
		break;
	}

}
void RandomDemon::back()
{
	m_dir = -m_dir;
}
void RandomDemon::setDirection(sf::Vector2f)
{
}
//bool RandomDemon::m_registerit = Factory::registerit("RandomDemon", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<RandomDemon>(r, c); });
