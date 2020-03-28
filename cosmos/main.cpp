#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "unit.h"
#include "graphics.h"

extern sf::RenderWindow window;
extern std::vector <Block *> all_blocks;
extern std::vector <Unit *> all_units;

sf::Vector2f tile_size(20., 20.);
sf::Vector2i tile_count(20, 10);
sf::Vector2f grid_size(tile_size.x * tile_count.x, tile_size.y * tile_count.y);
sf::Vector2f grid_offset(0, 0);

Map my_map(tile_count);

int main()
{
	init_graphics();

	Unit *unit = new Unit(0, 0);
	Block *b1 = new Block(4, 4);
	Block *b2 = new Block(4, 3);
	Block *b3 = new Block(4, 2);

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
					unit->move_by(sf::Vector2f(0, -1));
					break;
				}
				if (event.key.code == sf::Keyboard::A) {
					unit->move_by(sf::Vector2f(-1, 0));
					break;
				}
				if (event.key.code == sf::Keyboard::S) {
					unit->move_by(sf::Vector2f(0, 1));
					break;
				}
				if (event.key.code == sf::Keyboard::D) {
					unit->move_by(sf::Vector2f(1, 0));
					break;
				}
				if (event.key.code == sf::Keyboard::Up) {
					grid_offset.y = grid_offset.y + 1;
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					grid_offset.y = grid_offset.y - 1;
					break;
				}
				if (event.key.code == sf::Keyboard::Left) {
					grid_offset.x = grid_offset.x + 1;
					break;
				}
				if (event.key.code == sf::Keyboard::Right) {
					grid_offset.x = grid_offset.x - 1;
					break;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					int pos_x = event.mouseButton.x;
					int pos_y = event.mouseButton.y;
					if (pos_x >= grid_size.x or pos_y >= grid_size.y) {
						std::cout << "out of bounds" << std::endl;
					}
					else {
						std::cout << "in bounds" << std::endl;
					}
					/*std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;*/
				}
			default:
				break;
			}
		}
		window.clear();
		draw_map(my_map);

		for (std::vector<Unit *>::iterator it = all_units.begin(); it != all_units.end(); ++it) {
			draw_unit(**it);
		};

		for (std::vector<Block *>::iterator it = all_blocks.begin(); it != all_blocks.end(); ++it) {
			draw_block(**it);
		};

		window.display();
	}
	return 0;
}