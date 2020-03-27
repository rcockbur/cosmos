#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "unit.h"
#include "graphics.h"

sf::RenderWindow window(sf::VideoMode(800, 800), "cosmos");

sf::Vector2f tile_size(20., 20.);
sf::Vector2i tile_count(20, 10);
sf::Vector2f grid_size(tile_size.x * tile_count.x, tile_size.y * tile_count.y);
Map my_map(tile_count);

int main()
{
	
	Unit unit(3, 3);

	init_graphics();

	my_map.set_tile(sf::Vector2i(1, 1), false);
	my_map.set_tile(sf::Vector2i(2, 1), false);

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
		draw_map(map);
		draw_unit(unit);
		window.display();
	}
	return 0;
}