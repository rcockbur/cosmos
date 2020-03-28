#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "unit.h"
#include "map.h"
#include <iostream>

extern sf::Vector2f grid_size;
extern sf::Vector2f tile_size;
extern sf::Vector2f grid_offset;

sf::RenderWindow window(sf::VideoMode(900, 600), "cosmos");

sf::RectangleShape unit_shape;
sf::RectangleShape block_shape;
sf::RectangleShape line_vertical;
sf::RectangleShape line_horizontal;

void init_graphics() {
	window.setPosition(sf::Vector2i(0, 0));

	unit_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	unit_shape.setFillColor(sf::Color::Red);
	block_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	block_shape.setFillColor(sf::Color::Magenta);
	line_vertical.setSize(sf::Vector2f(1, grid_size.y));
	line_vertical.setFillColor(sf::Color::White);
	line_horizontal.setSize(sf::Vector2f(grid_size.x, 1));
	line_horizontal.setFillColor(sf::Color::White);
}

void draw_unit(Unit& unit) {
	
	unit_shape.setPosition(unit.get_position() + grid_offset);
	window.draw(unit_shape);
}

void draw_block(Block& block) {
	sf::Vector2f pos(block.get_tile().x * tile_size.x + 1.f, block.get_tile().y * tile_size.y + 1.f);
	block_shape.setPosition(pos + grid_offset);
	window.draw(block_shape);
}

void draw_map(Map& map) {
	for (int i = 0; i < map.get_size().x + 1; i++) {
		line_vertical.setPosition(sf::Vector2f(tile_size.x * i, 0.) + grid_offset);
		window.draw(line_vertical);
	}
	for (int i = 0; i < map.get_size().y + 1; i++) {
		line_horizontal.setPosition(sf::Vector2f(0., tile_size.y * i) + grid_offset);
		window.draw(line_horizontal);
	}
}