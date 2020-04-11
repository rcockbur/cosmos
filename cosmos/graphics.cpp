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
extern Entity * selected_entity_ptr;
extern Map my_map;

sf::RenderWindow window(sf::VideoMode(900, 600), "cosmos");
sf::RectangleShape selection_outline_shape;
sf::RectangleShape line_vertical;
sf::RectangleShape line_horizontal;

sf::Font sansation_font;
sf::Text sansation_text;


void init_graphics() {
	window.setPosition(sf::Vector2i(0, 0));
	line_vertical.setSize(sf::Vector2f(2, grid_size.y + 2.f));
	line_vertical.setFillColor(sf::Color::White);
	line_horizontal.setSize(sf::Vector2f(grid_size.x + 2.f, 2));
	line_horizontal.setFillColor(sf::Color::White);
	selection_outline_shape.setFillColor(sf::Color::Transparent);
	selection_outline_shape.setOutlineColor(sf::Color::Yellow);
	selection_outline_shape.setOutlineThickness(2.f);
	init_text();
}



void draw_map() {
	for (int i = 0; i < my_map.size.x + 1; i++) {
		line_vertical.setPosition(world_pos_to_screen_pos(sf::Vector2f(tile_size.x * i - 1, -1)));
		window.draw(line_vertical);
	}
	for (int i = 0; i < my_map.size.y + 1; i++) {
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

void draw_selection_outline() {
	if (selected_entity_ptr != nullptr) {
		Entity& e = (*selected_entity_ptr);
		sf::Vector2f screen_pos = world_pos_to_screen_pos(sf::Vector2f(e.position_rect.left, e.position_rect.top));
		selection_outline_shape.setSize(sf::Vector2f(e.position_rect.width, e.position_rect.height));
		selection_outline_shape.setPosition(screen_pos);
		window.draw(selection_outline_shape);
	}
}

void init_text() {
	if (!sansation_font.loadFromFile("sansation.ttf"))
		std::cout << "Error loading font\n";
	
	sansation_text.setFont(sansation_font);
	sansation_text.setCharacterSize(20);
	sansation_text.setStyle(sf::Text::Bold);
	sansation_text.setFillColor(sf::Color::Yellow);
	sansation_text.setOutlineColor(sf::Color::Magenta);
	sansation_text.setPosition(500, 100);
	

}

void draw_selected_status() {
	if (selected_entity_ptr != nullptr) {
		window.pushGLStates();
		std::ostringstream ss;
		if (dynamic_cast<Unit*>(selected_entity_ptr) != nullptr) {
			ss << "entity_id: " << selected_entity_ptr->entity_id;
		}
		else {
			ss << "entity_id: " << selected_entity_ptr->entity_id;
		}
		sansation_text.setString(ss.str());
		window.draw(sansation_text);
		window.popGLStates();	
	}
}