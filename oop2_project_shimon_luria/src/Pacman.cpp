#include "Pacman.h"
#include "PacShot.h"
//#include "Factory.h"



const auto s = sf::seconds(0.05f);

Pacman::Pacman(int r, int c)
	:MoveObject(r, c)
{
//	static bool m = Factory::registerit("Pacman", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<Pacman>(r, c); });
	m_numAnimates = 3;
	m_numPicX = 850;
	m_numPicY = 0;
	std::vector<sf::IntRect> locationPic;
	for (int i = 0; i < m_numAnimates; ++i)
	{
		locationPic.emplace_back(m_numPicX, m_numPicY, m_pixPicSize, m_pixPicSize);
		m_numPicY += (m_pixPicSize + m_distance);
	}
	for(auto r:locationPic)
		m_animate_pic.emplace_back(*(m_faceObject.getTexture()), r);

	for (auto& p : m_animate_pic)
	{
//		p.setPosition(m_position);
		p.setOrigin(sf::Vector2f(sf::Vector2u(m_pixPicSize, m_pixPicSize)/ 2u));
		p.setPosition(p.getOrigin() + m_position);
		p.scale(0.9, 0.9);
	}


	m_faceObject = m_animate_pic[0];
	m_resetPosition = m_animate_pic[0].getPosition();
}
void Pacman::setDirection(sf::Event& ev)
{

	switch (ev.key.code)
	{
		case sf::Keyboard::Right:
			if (m_dir != Direction(0, 0, 1, 0))
				unlock();
			m_dir = Direction(0, 0, 1, 0);
			for (auto& p : m_animate_pic)
				p.setRotation(0);
			break;
		case sf::Keyboard::Left:
			if (m_dir != Direction(0, 0, 0, 1))
				unlock();
			m_dir = Direction(0, 0, 0, 1);
			for (auto& p : m_animate_pic)
				p.setRotation(180);
			break;
		case sf::Keyboard::Up:
			if (m_dir != Direction(1, 0, 0, 0))
				unlock();
			m_dir = Direction(1, 0, 0, 0);
			for (auto& p : m_animate_pic)
				p.setRotation(270);
			break;
		case sf::Keyboard::Down:
			if (m_dir != Direction(0, 1, 0, 0))
				unlock();
			m_dir = Direction(0, 1, 0, 0);
			for (auto& p : m_animate_pic)
				p.setRotation(90);
			break;
		case sf::Keyboard::Enter:
			if(m_shots && m_dir != Direction(0,0,0,0))
			m_shot = true;
			break;
		case sf::Keyboard::Space:
			m_dir = Direction(0, 0, 0, 0);
			break;
	}
}
void Pacman::mov()
{
	sf::Time time = m_clock.getElapsedTime();
	float elapsed = time.asSeconds();
	m_delta = m_speed * elapsed * 2;
	movOnBoard(m_animate_pic, m_delta,&MoveObject::fixPosition);
	
	m_clock.restart();
	animate(time);
}
void Pacman::animate(sf::Time t)
{
	m_elapsed += t;
	if (m_elapsed >= s)
	{
		m_elapsed -= s;
		++m_animateIndex;
		m_animateIndex %= m_numAnimates;
	}

	m_faceObject = m_animate_pic[m_animateIndex];

}
std::unique_ptr<Shot> Pacman::PacShots()
{
	
	sf::Vector2f d (sf::Vector2f(m_faceObject.getGlobalBounds().width/2, m_faceObject.getGlobalBounds().height / 2));
	sf::Vector2f p = m_faceObject.getPosition() - d;
		//sf::Vector2f(m_size/2, m_size/2);
	if (!m_shot || m_dir == Direction(0, 0, 0, 0))
		return nullptr;
	else
	{
		m_shot = false;
		--m_shots;
		return std::make_unique<PacShot>(p, m_dir);
	}
}

void Pacman::back()
{
	float tmp = m_delta * -1;
	movOnBoard(m_animate_pic, tmp,&MoveObject::fixPosition);

		stop();
}
int Pacman::getLives()
{
	if (!m_status)
	{
		m_status = true;
		--m_lives;
	}
	else;
	return m_lives;


}
void Pacman::reset()
{
	for (auto& p : m_animate_pic)
		p.setPosition(m_resetPosition);
	m_faceObject.setPosition(m_resetPosition);

}
void Pacman::setInformation(Information info)
{
	m_lives = info.m_Lives;
	m_points = info.m_Points;
	m_shots = info.m_Shots;


}
//bool Pacman::m_registerit = Factory::registerit("Pacman", [](int r, int c) -> std::unique_ptr<Object> { return std::make_unique<Pacman>(r, c); });
