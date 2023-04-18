#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "Utilities.h"
#include "Object.h"
#include "MoveObject.h"
#include "Demon.h"
#include "Wall.h"
#include "SmartDemon.h"
#include "RandomDemon.h"
#include "Pacman.h"
#include "GiftShots.h"
#include "Shot.h"
#include "Menu.h"

class Level {
public:
	Level(std::ifstream& file, int, int);
	void draw();
	bool runLevel();
	void update();
	void addShots();
	void check_valid_update();

	void resetLevel();
	bool statusUpdatePac();
	bool finishLevel();
	void doEvents(sf::Event&);
	void printInfomation();
	Information getData() { return m_pac->getInformation(); }
	void addPointsLivesAndShots(Information inf) { m_pac->setInformation(inf); }
private:
	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Object>> m_statics;
	std::vector<std::unique_ptr<Demon>> m_demons;
	std::vector <std::unique_ptr<Shot>> m_shots;
	std::unique_ptr<Pacman> m_pac = nullptr;
	sf::Clock m_clockShots;
	unsigned int m_shotRate = 2;
	int m_row, m_col;
	bool m_stop = false;
	sf::Text text;
	int& m_speed;
	int& m_size;
	Menu m_menu;
};

template <typename FwdIt, typename Fn>
FwdIt _remove(FwdIt begin, FwdIt end, Fn fn);

template <typename FwdIt, typename FsecIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, FsecIt first, FsecIt last, Fn fn);
