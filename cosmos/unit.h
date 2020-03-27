#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Unit {
	sf::Vector2i tile;
	
public:
	Unit(sf::Vector2i& tile);
	Unit(int x, int y);
	void set_tile(sf::Vector2i& tile);
	sf::Vector2i& get_tile();
	void move_by(const sf::Vector2i&);
};
