#include "utility.h"
#include "ability.h"
#include "unit.h"
#include <SFML/System/Vector2.hpp>
#include <list>

Move::Move(Unit& unit, const sf::Vector2i& target_tile) : unit(unit) {
	path.push_back(sf::Vector2i(2., 2.));
	path.push_back(sf::Vector2i(3., 2.));
	path.push_back(sf::Vector2i(4., 2.));
	path.push_back(sf::Vector2i(5., 3.));
	path.push_back(sf::Vector2i(6., 4.));
	path.push_back(sf::Vector2i(7., 4.));
}

bool Move::execute() {
	if (path.size() > 0) {
		sf::Vector2f target(tile_to_world_pos_for_unit(path.front(), unit));
		sf::Vector2f vec1(target - sf::Vector2f(unit.position_rect.left, unit.position_rect.top));
		float magnitude = sqrt(pow(vec1.x, 2) + pow(vec1.y, 2));
		if (magnitude > 0.003f) {
			(vec1 /= magnitude) *= 0.003f;
		}
		unit.move_by(vec1);

		sf::Vector2f vec2(target - sf::Vector2f(unit.position_rect.left, unit.position_rect.top));
		magnitude = sqrt(pow(vec2.x, 2) + pow(vec2.y, 2));
		if (magnitude == 0.f) {
			path.pop_front();
			return false;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}