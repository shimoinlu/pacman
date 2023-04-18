#pragma once
class Utilities {
public:
	int m_size;
	int m_speed;
	int NUM_OF_LEVELS;
	Utilities& operator=(const Utilities&) = delete;
	Utilities (const Utilities&) = delete;
	static Utilities& getInstance();
private:
	Utilities() : m_size(40), m_speed(50), NUM_OF_LEVELS(3) {}
};