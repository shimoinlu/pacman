
#include "Game.h"

Game::Game()
	:m_speed(Utilities::getInstance().m_speed), m_size(Utilities::getInstance().m_size)
{
	static sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_text.setFont(font);
	std::ifstream file;
	file.open("objects.txt");
	std::string size;
	int counter = 0;

	//buliding levels
	while (1)
	{
		std::getline(file, size);
		if (size.empty())
			break;
		std::stringstream ss(size);
		ss >> m_sizeLevels[counter].y >> m_sizeLevels[counter].x;

		m_levels.emplace_back(std::make_unique<Level>(file, m_sizeLevels[counter].y, m_sizeLevels[counter].x));
		++counter;
	}
	file.close();

}

Game::~Game()
{
}

void Game::run()
{
	startGame();
	int l = 0;

	//loop run of all levels.
	for ( int i = l; i < m_levels.size(); ++i)

		//check if level finished successly in order to go to next level.
		if (m_levels[i]->runLevel())

			//check if level is not last level  he move pacman data to new pacman and increases speed.
			if (i + 1 < m_levels.size())
			{
				m_levels[i +  1]->addPointsLivesAndShots(m_levels[i]->getData());
				m_speed += 40;
			}
			else;

			else
			{
				printMassage("Failed. You had too many disqualifications.\n	Not bad in the next game you can win");
				exit(0);
			}
	printMassage("nice! you won the game");

}

void Game::startGame()
{
	std::string instruction = "Goodbye My friend.\n"
		"Some important notes for the Pacman game.\n"
		"You will be able to move Pacman with arrows. You \n"
		"can also stop it with press space bar. in addition you can  \n"
		"shoot shots with the enter key. You need to  \n"
		"be careful not to get stuck in elves or their shots.\n"
		"Below are details of points, lives, and shots. After the shots \n"
		"are over you will not be able to shoot. After life \n"
		"is over the game will be over.\n\n"

		"The icons of coins are a score. The icons of diamonds are life The\n"
		"icons of guns are shots.\n"

		"At the end of collecting all the coins you will go through a stage.\n"
	"There are icons to stop the gameand continue.There are also  -icons for\n"
		"increasing or decreasing speed\n"
		"for cintinue press space\n"
		"for close this window and start play press space";

	printMassage(instruction);
}

void Game::printMassage(std::string str)
{
	m_text.setString(str);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	m_text.setPosition(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);

	sf::RenderWindow wind(sf::VideoMode(unsigned int(m_text.getGlobalBounds().width) , unsigned int(m_text.getGlobalBounds().height) + 20), "");
	while (1)
	{
		if (auto event = sf::Event{}; wind.pollEvent(event))
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
				break;
			else if(event.type == sf::Event::Closed)
			{
				wind.close();
				exit(0);
			}
		wind.clear();
		wind.draw(m_text);
		wind.display();
	}
}
