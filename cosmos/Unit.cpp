#include "Unit.h"
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;
extern sf::RectangleShape unit_shape;
extern sf::Vector2f tile_size;

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

void Unit::draw() {
	unit_shape.setPosition(tile.x * tile_size.x + 1, tile.y * tile_size.y + 1);
	window.draw(unit_shape);
}

void Unit::move_by(const sf::Vector2i& vec) {
	tile.x = tile.x + vec.x;
	tile.y = tile.y + vec.y;
}