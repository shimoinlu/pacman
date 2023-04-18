#include "Object.h"

Object::Object(int r, int c)
	:m_speed(Utilities::getInstance().m_speed), m_size(Utilities::getInstance().m_size)
{
	m_position = sf::Vector2f(c * m_size, r * m_size);
	m_faceObject = sf::Sprite(getTexture());
	m_faceObject.setPosition(m_position);
}
void Object::draw(sf::RenderWindow& wnd)
{
	wnd.draw(m_faceObject);
}

sf::Texture& Object::getTexture()
{
	static sf::Texture Pacman;
	static int initlized = 0;

	if (!initlized)
	{
		initlized++;
		Pacman.loadFromFile("Pacman.png");

	}
	return Pacman;
}

