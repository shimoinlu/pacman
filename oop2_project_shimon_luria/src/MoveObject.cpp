#pragma once
#include "MoveObject.h"
#include "Shot.h"


const auto s = sf::seconds(0.05f);

sf::Vector2u MoveObject::m_sizeBoard = { 0,0 };
MoveObject::MoveObject(int r, int c)
	:Object(r,c)
{
	m_resetPosition = m_position;
}
void MoveObject::mov()
{

}
void MoveObject::movOnBoard(std::vector<sf::Sprite>& animateSprite, float delta,bool (MoveObject::*check_func)(sf::Vector2f))
{
	auto k = &check_func;
	if (delta > 2)
		return;
	sf::Rect dlt = animateSprite[0].getGlobalBounds();
	if (!m_stopRun)
	{
		return;
	}
	if (m_dir.RIGHT)

		if((this->*check_func)(sf::Vector2f(dlt.left + dlt.width + delta,dlt.top)))
		for (auto& p : animateSprite)
			p.move(delta, 0);
	if (m_dir.LEFT)
		if ((this->*check_func)(sf::Vector2f(dlt.left  - delta, dlt.top)))
			for (auto& p : animateSprite)
				p.move(-delta, 0);
	if (m_dir.UP)
		if ((this->*check_func)(sf::Vector2f(dlt.left, dlt.top - delta)))
			for (auto& p : animateSprite)
				p.move(0, -delta);
	if (m_dir.DOWN)
		if ((this->*check_func)(sf::Vector2f(dlt.left, dlt.top + dlt.height + delta)))
			for (auto& p : animateSprite)
				p.move(0, delta);
}

bool MoveObject::fixPosition(sf::Vector2f newPosition)
{
	if (newPosition.x < 0 || newPosition.y < 0
		|| newPosition.x > m_sizeBoard.x
		|| newPosition.y > m_sizeBoard.y)
		return false;
	return true;
}

void MoveObject::back()
{
}

