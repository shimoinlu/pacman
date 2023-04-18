#include "DemonShot.h"

DemonShot::DemonShot(sf::Vector2f position, Direction dir)
	:Shot(position, dir)
{
	for (auto& s : m_animate_pic)
		s.setColor(sf::Color::Red);
}
