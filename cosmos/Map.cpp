#include "Map.h"
#include <SFML/Graphics.hpp>
//#include <SFML/System/Vector2.hpp>
extern sf::RenderWindow window;
extern sf::CircleShape map_shape;
extern sf::RectangleShape line_horizontal;
extern sf::RectangleShape line_vertical;
extern float shape_size;
extern sf::Vector2f tile_size;
extern sf::Vector2i tile_count;
extern sf::Vector2f grid_size;



Map::Map(const sf::Vector2i& size) {
	this->size.x = size.x;
	this->size.y = size.y;
	tiles.resize(this->size.x);
	for (int i = 0; i < this->size.x; i++) {
		tiles[i].resize(this->size.y);
		for (int j = 0; j < this->size.y; j++) {
			tiles[i][j] = true;
		}
	}
}

void Map::set_tile(const sf::Vector2i& tile, bool val) {
	tiles[tile.x][tile.y] = val;
}

int Map::get_tile(const sf::Vector2i& tile) {
	return tiles[tile.x][tile.y];
}

void Map::draw() {
	/*for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			if (get_tile(sf::Vector2i(i, j)) == true) {
				map_shape.setPosition(shape_size * i * 2, grid_size.);
				window.draw(map_shape);
			}

		}
	}*/
}

void Map::draw_grid() {
	for (int i = 0; i < size.x + 1; i++) {
		line_horizontal.setPosition(tile_size.x * i, 0.);
		window.draw(line_horizontal);
	}
	for (int i = 0; i < size.y + 1; i++) {
		line_vertical.setPosition(0., tile_size.y * i);
		window.draw(line_vertical);
	}
}