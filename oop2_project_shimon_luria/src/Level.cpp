#pragma once
#include <algorithm>
#include "Level.h"
#include "ManageCollision.h"
#include "Pacman.h"
#include "GiftLives.h"
#include "GiftPoints.h"
#include "GiftShots.h"
#include "SmartDemon.h"
#include "RandomDemon.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>
#include "StopRun.h"
#include "Slow.h"
#include "Fast.h"
#include "Exceptions.h"



Level::Level(std::ifstream& file, int rows, int cols)
	:m_row(rows), m_col(cols), m_speed(Utilities::getInstance().m_speed), m_size(Utilities::getInstance().m_size)
	, m_menu(m_size* cols, m_stop)
{

	static sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text.setFont(font);

	int row, col;
	std::string line;
	std::string type;

	while (1) {
		//load objects from file
		std::getline(file, line);
		if (line == "######")
		{
			break;
		}
		std::stringstream obj(line);
		obj >> type >> row >> col;

		if (row >= m_row || col >= m_col)
			throw missPosition(row, col, sf::Vector2i{ m_col,m_row });
		//add elements for vectors game.
		if (type == "P")
			m_pac = std::make_unique<Pacman>(row, col);
		else if (type == "D_S")
			m_demons.emplace_back(std::make_unique<SmartDemon>(row, col));
		else if (type == "D_R")
			m_demons.emplace_back(std::make_unique<RandomDemon>(row, col));
		else if (type == "G_P")
			m_statics.emplace_back(std::make_unique<GiftPoints>(row, col));

		else if (type == "G_L")
			m_statics.emplace_back(std::make_unique<GiftLives>(row, col));
		else if (type == "G_S")
			m_statics.emplace_back(std::make_unique<GiftShots>(row, col));
		else if (type == "W")
			m_statics.emplace_back(std::make_unique<Wall>(row, col));
		else
			throw UnknownTypeCollision(type);		//exception throwed. not valid type

	}
	m_menu.add(std::make_unique<StopRun>());
	m_menu.add(std::make_unique<Fast>());
	m_menu.add(std::make_unique<Slow>());

}

void Level::draw()
{
	for (auto& s : m_statics)
		s->draw(m_window);
	for (auto& mv : m_demons)
		mv->draw(m_window);
	for (auto& s : m_shots)
		s->draw(m_window);

	m_pac->draw(m_window);
	m_menu.showAll(m_window);
}

bool Level::runLevel()
{
	MoveObject::setSizeBoard(sf::Vector2u(m_col * m_size, m_row * m_size));
	m_window.create(sf::VideoMode{ (unsigned)m_col * m_size + m_size, (unsigned)m_row * m_size + 50 }, "pacman");
	m_window.setFramerateLimit(100000);
	while (1)
	{
		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			doEvents(event);
		}
		m_window.clear();
		if (!m_stop)
		{
			//move all
			update();
			//check collission 
			check_valid_update();
			//print pacman data 
			printInfomation();
			//if pacman tead exit
			if (!statusUpdatePac())
				return false;
			//if all gift points removed from bord exit from level.
			if (finishLevel())
			{
				m_window.close();
				return true;
			}
			//add demon and pacman shots
			addShots();
		}
		draw();
		m_window.display();
	}
}

//move all

void Level::update()
{
	for (auto& d : m_demons)
	{
		d->setDirection(m_pac->getPosition());
		d->mov();
	}
	for (auto& s : m_shots)
		s->mov();
	m_pac->mov();
}

void Level::addShots()
{
	//clock fro demons shots 
	sf::Time time = m_clockShots.getElapsedTime();
	float elapsed = time.asSeconds();
	if (elapsed > m_shotRate)
	{
		for (auto& d : m_demons)
			m_shots.emplace_back(d->DemonShots());
		m_clockShots.restart();
	}
	auto ps = m_pac->PacShots();
	if (ps)
		m_shots.emplace_back(std::move(ps));
}



void Level::check_valid_update()
{
	std::vector <Pacman*>vecPac = { m_pac.get() };

	auto fu = [&](auto& a, auto& b) {		if (ManageCollision::collide(*a, *b))
		ManageCollision::processCollision(*a, *b); };

	auto rmv_fu = [&](auto& obj) {		return !obj->getStatus();	};

	//chck collision
	for_each_pair(m_statics.begin(), m_statics.end(), vecPac.begin(), vecPac.end(), fu);
	for_each_pair(m_statics.begin(), m_statics.end(), m_demons.begin(), m_demons.end(), fu);
	for_each_pair(m_statics.begin(), m_statics.end(), m_shots.begin(), m_shots.end(), fu);
	for_each_pair(m_shots.begin(), m_shots.end(), m_shots.begin(), m_shots.end(), fu);
	for_each_pair(m_demons.begin(), m_demons.end(), m_shots.begin(), m_shots.end(), fu);
	for_each_pair(m_demons.begin(), m_demons.end(), vecPac.begin(), vecPac.end(), fu);
	for_each_pair(m_shots.begin(), m_shots.end(), vecPac.begin(), vecPac.end(), fu);

	//	remove from vectors all dead object after collision
	m_statics.erase(_remove(m_statics.begin(), m_statics.end(), rmv_fu), m_statics.end());
	m_demons.erase(_remove(m_demons.begin(), m_demons.end(), rmv_fu), m_demons.end());
	m_shots.erase(_remove(m_shots.begin(), m_shots.end(), rmv_fu), m_shots.end());
}
//reset level after pacman dead.	
void Level::resetLevel()
{
	for (auto& de : m_demons)
		de->reset();
	m_pac->reset();
	m_shots.clear();
}
//check if pacman live
bool Level::statusUpdatePac()
{
	if (!m_pac->getStatus())
		if (m_pac->getLives())
			resetLevel();
		else
		{
			m_window.close();
			return false;
		}
	return true;
}
//check if exsist points that not selected
bool Level::finishLevel()
{
	auto it = std::find_if(m_statics.begin(), m_statics.end(), [](auto& a) {return a->name() == "GiftPoints"; });
	return it == m_statics.end();

}
void Level::doEvents(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		m_pac->setDirection(event);

	}
	else if (event.type == sf::Event::Closed)
	{
		m_window.close();
		exit(0);
	}
	else if (event.type == sf::Event::MouseButtonReleased)
		m_menu.contianPress(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));

}
void Level::printInfomation()
{
	std::string info = "points: " + std::to_string(m_pac->getInformation().m_Points)
		+ " Lives " + std::to_string(m_pac->getInformation().m_Lives) + " Shots "
		+ std::to_string(m_pac->getInformation().m_Shots);
	text.setString(info);
	text.setPosition(0.f, m_row * m_size);
	text.setColor(sf::Color::Blue);
	m_window.draw(text);


}
template <typename FwdIt, typename Fn>
FwdIt _remove(FwdIt begin, FwdIt end, Fn fn)
{
	return std::remove_if(begin, end, fn);
}

template <typename FwdIt, typename FsecIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, FsecIt first, FsecIt last, Fn fn)
{
	for (; begin != end; ++begin)
		for (auto second = first; second != last; ++second)
			fn(*begin, *second);
}
//void remove()