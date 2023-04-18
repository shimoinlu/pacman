#pragma once
#include "Command.h"


class Fast : public Command
{
public:
	Fast();
	virtual void doCmd(commandOperand& cmd);
	void virtual setPosition(sf::Vector2f position);
private:

};

