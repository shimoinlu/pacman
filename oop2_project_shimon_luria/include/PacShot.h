#pragma once
#include "Shot.h"
class PacShot : public Shot
{
public:
	PacShot(sf::Vector2f, Direction);
	virtual std::string name() { return "PacShot"; }
};