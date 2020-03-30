#pragma once
#include "unit.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Map {
	
	vector<vector<Block *> > tiles;
public:
	sf::Vector2i size;
	Map(const sf::Vector2i& size);
	void set_tile(const sf::Vector2i& tile, Block * block);
	Block * get_tile(const sf::Vector2i& tile);
};
