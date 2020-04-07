#include "actions.h"
#include "map.h"
#include "unit.h"
#include "block.h"

extern sf::Vector2f grid_size;
extern sf::Vector2i tile_count;
extern Map my_map;

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