#include "unit.h"
#include <SFML/Graphics.hpp>
#include "map.h"
#include <vector>
#include <iostream>

extern Map my_map;

std::vector <Block *> all_blocks;
std::vector <Unit *> all_units;

Block::Block(sf::Vector2i& tile) {
	this->tile.x = tile.x;
	this->tile.y = tile.y;
	all_blocks.push_back(this);
}

Block::Block(int x, int y) {
	this->tile.x = x;
	this->tile.y = y;
	all_blocks.push_back(this);
}

void Block::set_tile(sf::Vector2i& tile) {
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



Unit::Unit(sf::Vector2i& tile) {
	this->tile.x = tile.x;
	this->tile.y = tile.y;
	all_units.push_back(this);
}

Unit::Unit(int x, int y) {
	this->tile.x = x;
	this->tile.y = y;
	all_units.push_back(this);
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