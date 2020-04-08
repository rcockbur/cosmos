#include <vector>
#include <SFML/System/Vector2.hpp>
#include "unit.h"
#include <iostream>

std::vector<Unit *> all_units;

Unit * new_unit(const sf::Vector2i& tile) {
	all_units.push_back(new Unit(tile));
	return all_units.back();
}

void update_units() {
	for (std::vector<Unit *>::iterator it = all_units.begin(); it != all_units.end(); ++it) {
		(**it).update();
	}
}