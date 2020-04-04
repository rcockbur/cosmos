#include "unit.h"
#include <SFML/Graphics.hpp>
#include "map.h"
#include "utility.h"
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "ability.h"

extern Map my_map;
extern sf::RenderWindow window;
extern sf::Vector2i tile_count;
extern sf::Vector2f tile_size;
extern sf::Vector2f grid_size;
extern sf::CircleShape unit_shape;
extern sf::RectangleShape block_shape;

std::vector <Block *> all_blocks;
std::vector <Unit *> all_units;
sf::RectangleShape Unit::shape;
sf::RectangleShape Block::shape;

const float Unit::radius = 10;
const float Block::radius = 10;

void init_units() {
	Unit::shape.setSize(sf::Vector2f(Unit::radius * 2, Unit::radius * 2));
	Unit::shape.setFillColor(sf::Color::Red);
	Block::shape.setSize(sf::Vector2f(Block::radius * 2, Block::radius * 2));
	Block::shape.setFillColor(sf::Color::Magenta);
}

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

void Block::draw() {
	sf::Vector2f pos(tile.x * tile_size.x, tile.y * tile_size.y);
	shape.setPosition(world_pos_to_screen_pos(pos));
	window.draw(shape);
}

Unit::Unit(const sf::Vector2i& tile) {
	if (0 <= tile.x && tile.x < tile_count.x && 0 <= tile.y && tile.y < tile_count.y) {
		this->tile.x = tile.x;
		this->tile.y = tile.y;
		this->position = tile_center_to_world_pos(this->tile);
		all_units.push_back(this);
	}
	else throw "out of bounds";
}

void Unit::move_by(const sf::Vector2f& vec) {
	position.x = position.x + vec.x;
	position.y = position.y + vec.y;
}

void Unit::draw() {
	shape.setPosition(world_pos_to_screen_pos(position - sf::Vector2f(radius, radius)));
	window.draw(shape);
}

void Unit::update() {
	std::cout << ability_queue.size() << std::endl;
	if (ability_queue.size() > 0) {
		Ability * ability = ability_queue.back();
		if (ability->execute() == true)
			ability_queue.pop_back();
	}
	
}


void Unit::queue_up_move(const sf::Vector2i tile) {

}