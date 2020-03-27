#pragma once
#include "unit.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Map {
	sf::Vector2i size;
	vector<vector<Block *> > tiles;
public:
	Map(const sf::Vector2i& size);
	void set_tile(const sf::Vector2i& tile, Block * block);
	Block * get_tile(const sf::Vector2i& tile);
	sf::Vector2i& get_size();
};
