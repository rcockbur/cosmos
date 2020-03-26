#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Unit.h"

sf::RenderWindow window(sf::VideoMode(800, 800), "cosmos");

sf::Vector2f tile_size(20., 20.);
sf::Vector2i tile_count(20, 10);
sf::Vector2f grid_size(tile_size.x * tile_count.x, tile_size.y * tile_count.y);

sf::RectangleShape unit_shape;
sf::RectangleShape line_horizontal;
sf::RectangleShape line_vertical;

int main()
{
	Map map(tile_count);
	Unit unit(3, 3);

	unit_shape.setSize(sf::Vector2f(tile_size.x - 1, tile_size.y - 1));
	unit_shape.setFillColor(sf::Color::Red);
	line_horizontal.setSize(sf::Vector2f(1, grid_size.y));
	line_horizontal.setFillColor(sf::Color::White);
	line_vertical.setSize(sf::Vector2f(grid_size.x, 1));
	line_vertical.setFillColor(sf::Color::White);

	map.set_tile(sf::Vector2i(1, 1), false);
	map.set_tile(sf::Vector2i(2, 1), false);

	while (window.isOpen()) {
		sf::Clock clock;
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape){
					window.close();
					break;
				}
				if (event.key.code == sf::Keyboard::Q) {
					window.close();
					break;
				}
				if (event.key.code == sf::Keyboard::W) {
					unit.move_by(sf::Vector2i(0, -1));
					break;
				}
				if (event.key.code == sf::Keyboard::A) {
					unit.move_by(sf::Vector2i(-1, 0));
					break;
				}
				if (event.key.code == sf::Keyboard::S) {
					unit.move_by(sf::Vector2i(0, 1));
					break;
				}
				if (event.key.code == sf::Keyboard::D) {
					unit.move_by(sf::Vector2i(1, 0));
					break;
				}
				break;
			default:
				break;
			}
		}
		window.clear();
		map.draw_grid();
		unit.draw();
		window.display();
	}
	return 0;
}