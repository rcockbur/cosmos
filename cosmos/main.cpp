#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "unit.h"
#include "graphics.h"
#include "utility.h"
#include "actions.h"

extern sf::RenderWindow window;
extern Map my_map;
extern std::vector <Block *> all_blocks;
extern std::vector <Unit *> all_units;

sf::Vector2f tile_size(20., 20.);
sf::Vector2i tile_count(20, 10);
sf::Vector2f grid_size(tile_size.x * tile_count.x, tile_size.y * tile_count.y);
sf::Vector2f camera_pos(-50, -50);

int main()
{
	init_graphics();

	Unit *unit = new Unit(sf::Vector2f(0, 0));
	Block *block_1 = new Block(sf::Vector2i(4, 4));
	Block *block_2 = new Block(sf::Vector2i(4, 3));
	Block *block_3 = new Block(sf::Vector2i(4, 2));

	my_map.set_tile(sf::Vector2i(1, 1), false);
	my_map.set_tile(sf::Vector2i(2, 1), false);

	bool has_printed = false;
	
	while (window.isOpen()) {
		has_printed = false;
		sf::Clock clock;
		sf::Event event;
		while (window.pollEvent(event)) {
			sf::Vector2f screen_pos((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
			sf::Vector2f world_pos = screen_pos_to_world_pos(screen_pos);
			sf::Vector2i tile = world_pos_to_tile(world_pos);
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
					camera_pos.y = camera_pos.y - 5;
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					camera_pos.y = camera_pos.y + 5;
					break;
				}
				if (event.key.code == sf::Keyboard::Left) {
					camera_pos.x = camera_pos.x - 5;
					break;
				}
				if (event.key.code == sf::Keyboard::Right) {
					camera_pos.x = camera_pos.x + 5;
					break;
				}
				if (event.key.code == sf::Keyboard::B) {
					try_spawn_block(tile);
					break;
				}
				if (event.key.code == sf::Keyboard::U) {
					try_spawn_unit(world_pos);
					break;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					has_printed = true;
					std::cout << "screen_pos:" << screen_pos.x << ", " << screen_pos.y << std::endl;
					std::cout << "world_pos: " << world_pos.x << ", " << world_pos.y << std::endl;
					std::cout << "tile:   " << tile.x << ", " << tile.y << std::endl;
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

		for (std::vector<Block *>::iterator it = all_blocks.begin(); it != all_blocks.end(); ++it)
			draw_block(**it);

		window.display();
		if (has_printed)
			std::cout << "---------------------------------------------------------" << std::endl;
			has_printed = false;
	}
	return 0;
}