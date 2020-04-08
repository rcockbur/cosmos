#include "entity.h"
#include "unit.h"
#include <SFML/Graphics.hpp>
#include "map.h"
#include "utility.h"
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "ability.h"
#include <memory>

extern Map my_map;
extern sf::RenderWindow window; extern sf::Vector2f tile_size;
extern sf::Vector2i tile_count;

const sf::Vector2f Unit::size{ 18., 18. };
sf::RectangleShape Unit::shape;

void init_units() {
	Unit::shape.setSize(Unit::size);
	Unit::shape.setFillColor(sf::Color::Red);
}


Unit::Unit(const sf::Vector2i& tile) : Entity()
{
	sf::Vector2f pos = tile_center_to_world_pos(tile) - sf::Vector2f(size.x / 2, size.y / 2);
	this->position_rect.left = pos.x;
	this->position_rect.top = pos.y;
	this->position_rect.width = size.x;
	this->position_rect.height = size.y;
}

void Unit::move_by(const sf::Vector2f& vec) {
	this->position_rect.left += vec.x;
	this->position_rect.top += vec.y;
}

void Unit::draw() {
	shape.setPosition(world_pos_to_screen_pos(sf::Vector2f(position_rect.left, position_rect.top)));
	if (is_selected) {
		shape.setFillColor(sf::Color::Yellow);
	}
	else {
		shape.setFillColor(sf::Color::Red);
	}
	window.draw(shape);
}

void Unit::update() {
	if (ability_queue.size() > 0) {
		Ability * ability = ability_queue.back();
		if (ability->execute() == true)
			ability_queue.pop_back();
	}
}


void Unit::queue_up_move(const sf::Vector2i tile) {

}