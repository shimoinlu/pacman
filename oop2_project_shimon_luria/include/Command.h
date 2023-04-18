#pragma once
#include <SFML/Graphics.hpp>
struct commandOperand {
	commandOperand(int& speed, bool& run):m_stop(run),m_speed(speed){}
	int& m_speed;
	bool& m_stop;


};

class Command
{
public:
	Command()= default;
	virtual void doCmd(commandOperand& cmd) {}
	bool buttonPressed(sf::Vector2f psn) { return m_face.getGlobalBounds().contains(psn); }
	void draw(sf::RenderWindow& wnd) { wnd.draw(m_face); }
	void virtual setPosition(sf::Vector2f position) { m_face.setPosition(position); }
protected:
	sf::Sprite m_face;
	sf::Vector2f m_position;
	int DELTA_SPEED = 20;
};

