#pragma once
#include "Command.h"


class StopRun : public Command
{
public:
	StopRun();
	virtual void doCmd(commandOperand& cmd);
	void virtual setPosition(sf::Vector2f position);
private:
	sf::Sprite m_run;
	sf::Sprite m_stop;
	bool run = true;

};

