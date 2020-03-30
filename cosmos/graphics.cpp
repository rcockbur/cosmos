#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "unit.h"
#include "map.h"
#include <iostream>
#include "utility.h"
//#include <SFML/System/Vector2.hpp>

extern sf::Vector2f grid_size;
extern sf::Vector2f tile_size;
extern sf::Vector2f camera_pos;

sf::RenderWindow window(sf::VideoMode(900, 600), "cosmos");

sf::CircleShape unit_shape;
sf::RectangleShape block_shape;
sf::RectangleShape line_vertical;
sf::RectangleShape line_horizontal;

void init_graphics() {
	window.setPosition(sf::Vector2i(0, 0));

	unit_shape.setRadius(5);
	unit_shape.setFillColor(sf::Color::Red);
	block_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	block_shape.setFillColor(sf::Color::Magenta);
	line_vertical.setSize(sf::Vector2f(1, grid_size.y));
	line_vertical.setFillColor(sf::Color::White);
	line_horizontal.setSize(sf::Vector2f(grid_size.x, 1));
	line_horizontal.setFillColor(sf::Color::White);
}

void draw_unit(const Unit& unit) {
	unit_shape.setPosition(world_pos_to_screen_pos(unit.position));
	window.draw(unit_shape);
}

void draw_block(const Block& block) {
	sf::Vector2f pos(block.tile.x * tile_size.x + 1.f, block.tile.y * tile_size.y + 1.f);
	block_shape.setPosition(world_pos_to_screen_pos(pos));
	window.draw(block_shape);
}

void draw_map(const Map& map) {
	for (int i = 0; i < map.size.x + 1; i++) {
		line_vertical.setPosition(world_pos_to_screen_pos(sf::Vector2f(tile_size.x * i, 0.)));
		window.draw(line_vertical);
	}
	for (int i = 0; i < map.size.y + 1; i++) {
		line_horizontal.setPosition(world_pos_to_screen_pos(sf::Vector2f(0., tile_size.y * i)));
		window.draw(line_horizontal);
	}
}