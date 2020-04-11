#include "actions.h"
#include "map.h"
#include "unit.h"
#include "block.h"
#include "utility.h"
#include <iostream>

extern std::vector<Unit *> all_units;
extern sf::Vector2f grid_size;
extern sf::Vector2i tile_count;
extern Map my_map;

extern Entity * selected_entity_ptr;

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

void select_entity(const sf::Vector2f& world_pos) {
	if (world_pos_within_bounds(world_pos)) {
		for (std::vector<Unit *>::iterator it = all_units.begin(); it != all_units.end(); ++it) {
			if ((**it).position_rect.contains(world_pos)) {
				Entity * entity_ptr = dynamic_cast<Entity *>(*it);
				entity_ptr->select();
				return;
			}
		}
		sf::Vector2i tile = world_pos_to_tile(world_pos);
		Block * block_ptr = my_map.get_tile(tile);
		if (block_ptr != nullptr) {
			Entity * entity_ptr = dynamic_cast<Entity *>(block_ptr);
			(*entity_ptr).select();
		}
	}
}

void move_selected_by(const sf::Vector2f& vec) {
	if (selected_entity_ptr != nullptr) {
		Unit * unit_ptr = dynamic_cast<Unit*>(selected_entity_ptr);
		if (unit_ptr != nullptr) {
			(*unit_ptr).move_by(vec);
		}
	}
}