#pragma once
#include "Game.h"
#include <iostream>
#include <exception>
#include <fstream>
#include "Level.h"
#include "Pacman.h"
#include "GiftPoints.h"
#include "GiftLives.h"
#include "GiftShots.h"
#include "SmartDemon.h"
#include "RandomDemon.h"
#include "Wall.h"
#include "Shot.h"
#include "Exceptions.h"
#include <typeinfo>

void f()
{
	std::cout << "shimon";
	exit(0);
}
int main()
{
	std::ofstream errorData;

	try {
	Game g;
	g.run();
	}
	catch (std::runtime_error& error)
	{
		errorData.open("Log.txt");
		errorData << error.what();
		errorData.close();

	}
	return 0;
}