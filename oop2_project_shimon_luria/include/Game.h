#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
//#include "Utilities.h"
#include "Level.h"
class Game {
public:
	Game();
	~Game();
	void run();
	void startGame();
	void printMassage(std::string str);
private:

	sf::Text m_text;
	//	sf::RenderWindow m_wind;
	sf::Vector2i m_sizeLevels[3];
	std::vector<std::unique_ptr<Level>> m_levels;
	int& m_speed;
	int& m_size;

};