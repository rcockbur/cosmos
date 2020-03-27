#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "unit.h"
#include "map.h"
#include <iostream>

extern sf::RenderWindow window;
extern sf::Vector2f grid_size;
extern sf::Vector2f tile_size;

sf::RectangleShape unit_shape;
sf::RectangleShape block_shape;
sf::RectangleShape line_horizontal;
sf::RectangleShape line_vertical;

void init_graphics() {
	unit_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	unit_shape.setFillColor(sf::Color::Red);
	block_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	block_shape.setFillColor(sf::Color::Magenta);
	line_horizontal.setSize(sf::Vector2f(1, grid_size.y));
	line_horizontal.setFillColor(sf::Color::White);
	line_vertical.setSize(sf::Vector2f(grid_size.x, 1));
	line_vertical.setFillColor(sf::Color::White);
}

void draw_unit(Unit& unit) {
	sf::Vector2f pos(unit.get_tile().x * tile_size.x + 1.f, unit.get_tile().y * tile_size.y + 1.f);
	unit_shape.setPosition(pos);
	window.draw(unit_shape);
}

void draw_block(Block& block) {
	sf::Vector2f pos(block.get_tile().x * tile_size.x + 1.f, block.get_tile().y * tile_size.y + 1.f);
	block_shape.setPosition(pos);
	window.draw(block_shape);
	std::cout << "draw_block";
}

void draw_map(Map& map) {
	for (int i = 0; i < map.get_size().x + 1; i++) {
		line_horizontal.setPosition(tile_size.x * i, 0.);
		window.draw(line_horizontal);
	}
	for (int i = 0; i < map.get_size().y + 1; i++) {
		line_vertical.setPosition(0., tile_size.y * i);
		window.draw(line_vertical);
	}
}