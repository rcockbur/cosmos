#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;


class Block {
public:
	sf::Vector2i tile;
	sf::Vector2f position;
	Block(const sf::Vector2i& tile);
	void set_tile(const sf::Vector2i& tile);
	sf::Vector2i& get_tile();
	void move_by(const sf::Vector2i&);
};

class Unit {
public:
	sf::Vector2f position;
	float size;
	Unit(const sf::Vector2f& tile);
	void move_by(const sf::Vector2f&);
};