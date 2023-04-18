#include <algorithm>
#include "Menu.h"

void Menu::add(std::unique_ptr<Command> command)
{
	m_commands.emplace_back(std::move(command));
	m_commands[m_commands.size() - 1]->setPosition(m_position);
	m_position.y += m_size;
}

void Menu::contianPress(const sf::Vector2f& positionPressed)
 {
	auto it = std::find_if(m_commands.begin(), m_commands.end(),
		[&](auto& c) {return c->buttonPressed(positionPressed); });
	if (it != m_commands.end())
		(*it)->doCmd(m_co);

}

void Menu::showAll(sf::RenderWindow& wind)
{
	for (auto& c : m_commands)
		c->draw(wind);
}

//void Menu::contianPress(sf::Vector2f position)
//{
//	auto it = std::find_if(m_commands.begin(), m_commands.end(),
//		[&](auto& c) {return c->buttonPressed(position); });
//	if (it != m_commands.end())
//		(*it)->doCmd(m_co);
//}
