#include "Unit.h"
#include <SFML/Graphics.hpp>
#include "map.h"

extern Map my_map;

Unit::Unit(sf::Vector2i& tile) {
	this->tile.x = tile.x;
	this->tile.y = tile.y;
}

Unit::Unit(int x, int y) {
	this->tile.x = x;
	this->tile.y = y;
}

void Unit::set_tile(sf::Vector2i& tile) {
	this->tile.x = tile.x;
	this->tile.y = tile.y;
}

sf::Vector2i& Unit::get_tile() {
	return tile;

}

void Unit::move_by(const sf::Vector2i& vec) {
	tile.x = tile.x + vec.x;
	tile.y = tile.y + vec.y;
}