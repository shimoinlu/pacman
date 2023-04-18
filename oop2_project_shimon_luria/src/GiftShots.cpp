#pragma once
#include "GiftShots.h"
GiftShots::GiftShots(int r, int c)
	:NonMoveObject(r, c)
{
	//static sf::Texture face;
	//face.loadFromFile("giftShots.png");
	m_faceObject = sf::Sprite(getTexture());

	//	m_faceObject = sf::Sprite(face);
	m_faceObject.setPosition(m_position);
}

sf::Texture& GiftShots::getTexture()
{
	static sf::Texture giftShots;
	static int initlized = 0;

	if (!initlized)
	{
		initlized++;
		giftShots.loadFromFile("giftShots.png");

	}
	return giftShots;
}
