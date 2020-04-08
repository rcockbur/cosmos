#include <SFML/Graphics.hpp>
#include "graphics.h"
#include "unit.h"
#include "block.h"
#include "map.h"
#include <iostream>
#include "utility.h"
#include <vector>
#include <sstream>
#include <memory>

extern sf::Vector2f grid_size;
extern sf::Vector2f tile_size;
extern sf::Vector2f camera_pos;
extern std::vector <Block *> all_blocks;
extern std::vector<Unit *> all_units;
extern Entity * selected_entity;

sf::RenderWindow window(sf::VideoMode(900, 600), "cosmos");
sf::RectangleShape unit_shape;
sf::RectangleShape block_shape;
sf::RectangleShape line_vertical;
sf::RectangleShape line_horizontal;

sf::Font sansation_font;
sf::Text sansation_text;


void init_graphics() {
	window.setPosition(sf::Vector2i(0, 0));
	line_vertical.setSize(sf::Vector2f(2, grid_size.y));
	line_vertical.setFillColor(sf::Color::White);
	line_horizontal.setSize(sf::Vector2f(grid_size.x, 2));
	line_horizontal.setFillColor(sf::Color::White);

	init_text();
}



void draw_map(const Map& map) {
	for (int i = 0; i < map.size.x + 1; i++) {
		line_vertical.setPosition(world_pos_to_screen_pos(sf::Vector2f(tile_size.x * i - 1, -1)));
		window.draw(line_vertical);
	}
	for (int i = 0; i < map.size.y + 1; i++) {
		line_horizontal.setPosition(world_pos_to_screen_pos(sf::Vector2f(-1, tile_size.y * i - 1)));
		window.draw(line_horizontal);
	}
}

void draw_blocks() {
	for (std::vector<Block *>::iterator it = all_blocks.begin(); it != all_blocks.end(); ++it) {
		
		(**it).draw();
	}
		
}

void draw_units() {
	for (std::vector<Unit *>::iterator it = all_units.begin(); it != all_units.end(); ++it) {
		(**it).draw();
	}
}

void init_text() {
	if (!sansation_font.loadFromFile("sansation.ttf"))
		std::cout << "Error loading font\n";
	
	sansation_text.setFont(sansation_font);
	sansation_text.setCharacterSize(20);
	sansation_text.setStyle(sf::Text::Bold);
	sansation_text.setFillColor(sf::Color::Yellow);
	sansation_text.setOutlineColor(sf::Color::Yellow);
	sansation_text.setPosition(500, 100);
	

}

void draw_selected() {
	if (selected_entity != nullptr) {
		if (dynamic_cast<Unit*>(selected_entity) != nullptr) {
			window.pushGLStates();
			window.draw(sansation_text);
			window.popGLStates();
			std::ostringstream ss;
			ss << "entity_id: " << selected_entity->entity_id;
			sansation_text.setString(ss.str());
		}
		
	}
}