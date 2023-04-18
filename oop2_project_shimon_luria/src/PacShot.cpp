#include "PacShot.h"

PacShot::PacShot(sf::Vector2f position, Direction dir)
	:Shot(position,dir)
{
	for (auto& s : m_animate_pic)
		s.setColor(sf::Color::Cyan);

}
