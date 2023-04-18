#pragma once
#include "NonMoveObject.h"
class NonMoveObject;
class GiftShots :public NonMoveObject
{
public:
	GiftShots(int, int);
	static sf::Texture& getTexture();

	virtual std::string name() { return "GiftShots"; }
};