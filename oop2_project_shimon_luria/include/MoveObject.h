#pragma once
#include "Object.h"
#include "Direction.h"
class MoveObject : public Object
{
public:
	MoveObject(int, int);
	virtual std::string name() { return ""; }
	virtual void mov();
	//update all animations sprites 
	void movOnBoard(std::vector<sf::Sprite>& animateSprite, float delta, bool(MoveObject::*check_func)(sf::Vector2f));
	//select sprite accord to clock
	virtual void animate(sf::Time) {}
	//check if objects is in range of board
	bool fixPosition(sf::Vector2f);
	virtual void reset(){}
	virtual void back();
	void stop() { m_stopRun = false; }
	void unlock() { m_stopRun = true; }
	static void setSizeBoard(sf::Vector2u size) { m_sizeBoard = size; }
	bool emptyFunc(sf::Vector2f){return true; };
protected:
	sf::Clock m_clock;
	Direction m_dir;
	sf::Time m_elapsed;
	float m_elepsedAniate= 0.5f;
	float m_delta = 0.f;
	int m_numPicX = 0;
	int m_numPicY = 0;
	int m_numAnimates = 0;
	int m_pixPicSize = 40;
	int m_distance = 10;
	int m_animateIndex = 0;
	sf::Vector2f m_resetPosition;
	static sf::Vector2u m_sizeBoard;
	bool m_stopRun = true;
};
