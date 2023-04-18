#include "Wall.h"

Wall::Wall(int r, int c)
	:NonMoveObject(r,c)
{
	static sf::Texture wall;
	wall.loadFromFile("wall.png");
	m_faceObject = sf::Sprite(wall);
	m_faceObject.setPosition(Object::m_position);

}

sf::Texture& Wall::getTexture()
{
		static sf::Texture Wall;
		static int initlized = 0;

		if (!initlized)
		{
			initlized++;
			Wall.loadFromFile("wall.png");

		}
		return Wall;
}
