#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;


class Block {
	sf::Vector2i tile;
	//int block_id;
public:
	Block(sf::Vector2i& tile);
	Block(int x, int y);
	void set_tile(sf::Vector2i& tile);
	sf::Vector2i& get_tile();
	void move_by(const sf::Vector2i&);
};

class Unit {
	sf::Vector2f position;
	
public:
	Unit(sf::Vector2f& tile);
	Unit(float x, float y);
	void set_position(sf::Vector2f& tile);
	sf::Vector2f& get_position();
	void move_by(const sf::Vector2f&);
};