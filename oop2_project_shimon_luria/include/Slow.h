#pragma once
#include "Command.h"


class Slow : public Command
{
public:
	Slow();
	virtual void doCmd(commandOperand& cmd);
	void virtual setPosition(sf::Vector2f position);
private:

};

