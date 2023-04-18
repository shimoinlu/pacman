#pragma once
#include "MoveObject.h"
#include "Shot.h"
#include "Information.h"


//class Factory;
class Pacman : public MoveObject
{
public:
	Pacman(int, int);
	virtual std::string name() {return "Pacman";}
	virtual void setDirection(sf::Event&);
	virtual void mov();
	virtual void animate(sf::Time);
	sf::Vector2f getPosition() { return m_faceObject.getPosition(); }
	std::unique_ptr<Shot> PacShots();
	virtual void back();	// if pac collide with wall  or go out of range back
	void addPoints() { m_points++; }
	void addLives() { ++m_lives; }
	int getLives();
	void addShots() { ++m_shots; }
	virtual void reset();
	void setInformation(Information info);
	Information getInformation() { return Information(m_lives, m_points, m_shots); }
private:
	int m_lives = 3;
	int m_points = 0;
	int m_shots = 5;
	bool m_shot = false;
	std::vector<sf::Sprite> m_animate_pic;
	

};