#include "Slow.h"

Slow::Slow()
{
	static sf::Texture textureMinus;
	textureMinus.loadFromFile("minus.png");
	m_face = sf::Sprite(textureMinus);
}

void Slow::setPosition(sf::Vector2f position)
{
	m_face.setPosition(position);
}

void Slow::doCmd(commandOperand& cmd)
{
	if (!cmd.m_stop && cmd.m_speed >= 20)
		cmd.m_speed -= DELTA_SPEED;
	else
		;
}
