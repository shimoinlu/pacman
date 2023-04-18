#pragma once
#include "NonMoveObject.h"
class Wall :public NonMoveObject
{
public:
	Wall(int, int);
	static sf::Texture& getTexture();

	virtual std::string name() { return "Wall"; }

};