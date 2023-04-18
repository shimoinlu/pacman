#include "StopRun.h"

StopRun::StopRun()
{
	static sf::Texture stop;
	stop.loadFromFile("stop.png");
	static sf::Texture run;
	run.loadFromFile("play.png");
	m_run = sf::Sprite(run);
	m_stop = sf::Sprite(stop);
}

void StopRun::setPosition(sf::Vector2f position)
{
	m_run.setPosition(position);
	m_stop.setPosition(position);
	m_face = m_stop;
}

void StopRun::doCmd(commandOperand& cmd)
{
	if (run)
		m_face = m_run;
	else
		m_face = m_stop;
		run = !run;
	cmd.m_stop = !cmd.m_stop;
}
