#include "actions.h"
#include "map.h"
#include "unit.h"
#include "block.h"
#include "utility.h"
#include <iostream>
//#include <vector>

extern std::vector<Unit *> all_units;
extern sf::Vector2f grid_size;
extern sf::Vector2i tile_count;
extern Map my_map;

extern Entity * selected_entity;

void try_spawn_unit(const sf::Vector2i& tile) {
	if (0 <= tile.x && tile.x < tile_count.x && 0 <= tile.y && tile.y < tile_count.y) {
		new Unit(tile);
	}
}

void try_spawn_block(const sf::Vector2i& tile) {
	if (0 <= tile.x && tile.x < tile_count.x && 0 <= tile.y && tile.y < tile_count.y) {
		if (my_map.get_tile(tile) == nullptr) {
			new Block(tile);
		}
	}
}

void select_entity(const sf::Vector2f& position) {
	for (std::vector<Unit *>::iterator it = all_units.begin(); it != all_units.end(); ++it) {
		if ((**it).position_rect.contains(position)) {
			(**it).is_selected = true;
			selected_entity = *it;
		}
	}
}