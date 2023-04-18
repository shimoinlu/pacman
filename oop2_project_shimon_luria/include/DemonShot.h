#pragma once
#include "Shot.h"
class DemonShot : public Shot
{
public:
	DemonShot(sf::Vector2f, Direction);
	virtual std::string name() { return "DemonShot"; }
};