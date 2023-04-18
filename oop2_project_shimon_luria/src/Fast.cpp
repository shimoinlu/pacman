#include "Fast.h"

Fast::Fast()
{
	static sf::Texture textureMinus;
	textureMinus.loadFromFile("plus.png");
	m_face = sf::Sprite(textureMinus);
}

void Fast::setPosition(sf::Vector2f position)
{
	m_face.setPosition(position);
}

void Fast::doCmd(commandOperand& cmd)
{
	if (!cmd.m_stop)
		cmd.m_speed += DELTA_SPEED;
	else
		;
}
