#include "GiftPoints.h"
//#include "Factory.h"
GiftPoints::GiftPoints(int r, int c)
	:NonMoveObject(r, c)
{
	//static sf::Texture gift;
	//gift.loadFromFile("giftPoints.png");
	
	m_faceObject = sf::Sprite(getTexture());
	m_faceObject.setPosition(m_position);
}
sf::Texture& GiftPoints::getTexture()
{
	static sf::Texture giftPoints;
	static int initlized = 0;

	if (!initlized)
	{
		initlized++;
		giftPoints.loadFromFile("giftPoints.png");

	}
	return giftPoints;
}


//bool GiftPoints::m_registerit = Factory::registerit("GiftPoints", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<GiftPoints>(r, c); });
