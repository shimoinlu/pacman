#include "GiftLives.h"
GiftLives::GiftLives(int r, int c)
	:NonMoveObject(r,c)
{
	
	m_faceObject = sf::Sprite(getTexture());
	m_faceObject.setPosition(m_position);
}
sf::Texture& GiftLives::getTexture()
{
	static sf::Texture giftLives;
	static int initlized = 0;

	if (!initlized)
	{
		initlized++;
		giftLives.loadFromFile("giftLives.png");

	}
	return giftLives;
}
