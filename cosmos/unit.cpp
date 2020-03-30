#include "unit.h"
#include <SFML/Graphics.hpp>
#include "map.h"
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>

extern Map my_map;
extern sf::Vector2i tile_count;
extern sf::Vector2f tile_size;
extern sf::Vector2f grid_size;
std::vector <Block *> all_blocks;
std::vector <Unit *> all_units;

Block::Block(const sf::Vector2i& tile) {
	if (0 <= tile.x && tile.x < tile_count.x && 0 <= tile.y && tile.y < tile_count.y) {
		if (my_map.get_tile(tile) == nullptr) {
			this->tile.x = tile.x;
			this->tile.y = tile.y;
			all_blocks.push_back(this);
			my_map.set_tile(tile, this);
		}
		else throw "tile is occupied";
	}
	else throw "out of bounds";
}

void Block::set_tile(const sf::Vector2i& tile) {
	this->tile.x = tile.x;
	this->tile.y = tile.y;
}

sf::Vector2i& Block::get_tile() {
	return tile;

}

void Block::move_by(const sf::Vector2i& vec) {
	tile.x = tile.x + vec.x;
	tile.y = tile.y + vec.y;
}



Unit::Unit(const sf::Vector2f& position) {
	if (0 <= position.x && position.x + 5 < grid_size.x && 0 <= position.y && position.y + 5 < grid_size.y) {
		this->position.x = position.x;
		this->position.y = position.y;
		all_units.push_back(this);
	}
	else throw "out of bounds";
}

void Unit::move_by(const sf::Vector2f& vec) {
	position.x = position.x + vec.x;
	position.y = position.y + vec.y;
}