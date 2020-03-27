#include "Map.h"
#include <SFML/Graphics.hpp>

Map::Map(const sf::Vector2i& size) {
	this->size.x = size.x;
	this->size.y = size.y;
	tiles.resize(this->size.x);
	for (int i = 0; i < this->size.x; i++) {
		tiles[i].resize(this->size.y);
		for (int j = 0; j < this->size.y; j++) {
			tiles[i][j] = nullptr;
		}
	}
}

void Map::set_tile(const sf::Vector2i& tile, Block * block) {
	tiles[tile.x][tile.y] = block;
}

Block * Map::get_tile(const sf::Vector2i& tile) {
	return tiles[tile.x][tile.y];
}

sf::Vector2i& Map::get_size() {
	return size;
}
