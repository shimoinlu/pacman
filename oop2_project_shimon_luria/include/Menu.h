#pragma once
#include <memory>
#include <vector>
#include "Command.h"
#include "Utilities.h"
class Menu 
{
public:
	Menu(float x,bool& stop) :m_position(sf::Vector2f(x,0.f)),
		m_co(Utilities::getInstance().m_speed,stop),m_size(Utilities::getInstance().m_size)

	{}
	void add(std::unique_ptr<Command> command);
	void contianPress(const sf::Vector2f& positionPressed);
	void showAll(sf::RenderWindow& wind);
private:
	sf::Vector2f m_position;
	std::vector<std::unique_ptr<Command>> m_commands;
	int& m_size;
	struct commandOperand m_co;

};					