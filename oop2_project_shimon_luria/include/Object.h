#pragma once
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Object {
public:
	
	Object(int, int);
	sf::Sprite& getSprite() { return m_faceObject; }
	bool getStatus() { return m_status; }
	virtual std::string name() { return ""; }
	void kill() { m_status = false; }
	void draw(sf::RenderWindow&);
	static sf::Texture& getTexture();
	sf::FloatRect getBound() { return m_faceObject.getGlobalBounds(); }
protected:
	sf::Vector2f m_position;
	sf::Sprite m_faceObject;
	bool m_status = true;
	int& m_speed;
	int& m_size;
};
