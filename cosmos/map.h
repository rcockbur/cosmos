#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;

class Map {
	sf::Vector2i size;
	vector<vector<int> > tiles;
public:
	Map(const sf::Vector2i& size);
	void set_tile(const sf::Vector2i& tile, bool val);
	int get_tile(const sf::Vector2i& tile);
	sf::Vector2i& get_size();
};
