#include "Map.h"
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;
extern sf::CircleShape shape;
extern float shape_size;

Map::Map(int x, int y) {
	size[0] = x;
	size[1] = y;
	tiles.resize(x);
	for (int i = 0; i < x; i++) {
		tiles[i].resize(y);
		for (int j = 0; j < y; j++) {
			tiles[i][j] = true;
		}
	}
}

void Map::set_tile(int x, int y, bool val) {
	tiles[x][y] = val;
}

int Map::get_tile(int x, int y) {
	return tiles[x][y];
}

void Map::draw() {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			if (get_tile(i, j) == true) {
				shape.setPosition(shape_size * i * 2, shape_size * j * 2);
				window.draw(shape);
			}

		}
	}
}