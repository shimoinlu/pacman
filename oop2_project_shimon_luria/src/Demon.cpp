#pragma once
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <string>
#include "Demon.h"
#include "DemonShot.h"


const auto s = sf::seconds(0.05f);

Demon::Demon(int r, int c)
	:MoveObject(r, c)
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	int demon_color = std::rand() % 6;
	m_faceObject.setPosition(m_position);


	m_numAnimates = 3;
	m_numPicX = demon_color * (m_distance + m_pixPicSize);
	m_numPicY = 0;

	sf::IntRect up(m_numPicX, 300, m_pixPicSize, m_pixPicSize);
	sf::IntRect down(m_numPicX, 300, m_pixPicSize, m_pixPicSize);
	sf::IntRect right(m_numPicX, 0, m_pixPicSize, m_pixPicSize);
	sf::IntRect left(m_numPicX, 200, m_pixPicSize, m_pixPicSize);

	m_animate_pic_right.emplace_back(*(m_faceObject.getTexture()), up);
	m_animate_pic_right.emplace_back(*(m_faceObject.getTexture()), right);
	m_animate_pic_right.emplace_back(*(m_faceObject.getTexture()), down);

	m_animate_pic_left.emplace_back(*(m_faceObject.getTexture()), up);
	m_animate_pic_left.emplace_back(*(m_faceObject.getTexture()), left);
	m_animate_pic_left.emplace_back(*(m_faceObject.getTexture()), down);

	for (auto& d : m_animate_pic_left)
	{
		d.setOrigin(sf::Vector2f(sf::Vector2u(m_pixPicSize, m_pixPicSize) / 2u));
		d.setPosition(d.getOrigin() + m_position);
		d.scale(0.9, 0.9);
	}
	for (auto& d : m_animate_pic_right)
	{
		d.setOrigin(sf::Vector2f(sf::Vector2u(m_pixPicSize, m_pixPicSize) / 2u));
		d.setPosition(d.getOrigin() + m_position);
		d.scale(0.9, 0.9);
	}
	m_faceObject = m_animate_pic_left[0];
	m_resetPosition = m_animate_pic_left[0].getPosition();

}
void Demon::mov()
{
	sf::Time time = m_clock.getElapsedTime();
	float elapsed = time.asSeconds();
	m_delta = elapsed * m_speed;
	movOnBoard(m_animate_pic_right, m_delta,&MoveObject::fixPosition);
	movOnBoard(m_animate_pic_left, m_delta, &MoveObject::fixPosition);
	m_clock.restart();
	animate(time);
}
void Demon::setDirection(sf::Vector2f)
{
}
void Demon::back()
{
	float tmp = m_delta * -1;
	movOnBoard(m_animate_pic_right, tmp, &MoveObject::fixPosition);
	movOnBoard(m_animate_pic_left, tmp, &MoveObject::fixPosition);

}
void Demon::reset()
{
	for (auto& de : m_animate_pic_left)
		de.setPosition(m_resetPosition);
	for (auto& de : m_animate_pic_right)
		de.setPosition(m_resetPosition);
	m_faceObject.setPosition(m_resetPosition);
}
std::unique_ptr<Shot> Demon::DemonShots()
{
	sf::Vector2f d(sf::Vector2f(m_faceObject.getGlobalBounds().width / 2, m_faceObject.getGlobalBounds().height / 2));
	sf::Vector2f p = m_faceObject.getPosition() - d;

	auto k = sf::Vector2f(m_faceObject.getTexture()->getSize() / 2u);
	return std::make_unique<DemonShot>(p, m_dir);
}
void Demon::animate(sf::Time t)
{
	m_elapsed += t;
	if (m_elapsed >= s)
	{
		m_elapsed -= s;
		++m_animateIndex;
		m_animateIndex %= m_numAnimates;
	}
	if (m_dir.RIGHT || m_dir.UP)
		m_faceObject = m_animate_pic_right[m_animateIndex];
	else if (m_dir.LEFT || m_dir.DOWN)
		m_faceObject = m_animate_pic_left[m_animateIndex];
}
//bool Demon::m_registerit = Factory::registerit("Demon", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<Demon>(r, c); });
