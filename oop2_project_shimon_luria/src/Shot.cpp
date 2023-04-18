#include "Shot.h"

const auto s = sf::seconds(0.05f);

Shot::Shot(sf::Vector2f position, Direction dir)
	:MoveObject(0,0)
{
	m_numAnimates = 2;
	m_animate_pic.emplace_back(*(m_faceObject.getTexture()), sf::IntRect(528, 596, 30, 30));
	m_animate_pic.emplace_back(*(m_faceObject.getTexture()), sf::IntRect(507, 612, 17, 17));
	m_dir = dir;

	for (auto& sh : m_animate_pic)
	{
		sh.setPosition(position);
		sh.setOrigin(sf::Vector2f(sf::Vector2u(sh.getTexture()->getSize()) / 2u));	
    	sh.setPosition(sh.getOrigin() + m_animate_pic[0].getPosition());
	}
	m_faceObject = m_animate_pic[0];
}

void Shot::mov()
{
	sf::Time time = m_clock.getElapsedTime();
	float elapsed = time.asSeconds();
	movOnBoard(m_animate_pic, elapsed * m_speed * 4,&MoveObject::emptyFunc);
	m_clock.restart();
	animate(time);
}

void Shot::back()
{
}

void Shot::animate(sf::Time t)
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
