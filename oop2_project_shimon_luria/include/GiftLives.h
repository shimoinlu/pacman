#pragma once
#include "NonMoveObject.h"

//class NonMoveObject;
class GiftLives :public NonMoveObject
{
public:
	GiftLives(int, int);
	static sf::Texture& getTexture();
	virtual std::string name() { return "GiftLives"; }
	//	static bool m;
};

