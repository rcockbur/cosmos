#include "entity.h"
#include "block.h"
#include "map.h"
#include "utility.h"
#include <SFML/Graphics/Rect.hpp>

extern sf::Vector2i tile_count;
extern sf::Vector2f tile_size;
extern sf::RenderWindow window; extern sf::Vector2f tile_size;
extern Map my_map;

std::vector <Block *> all_blocks;
sf::RectangleShape Block::shape;
const sf::Vector2f Block::size(38, 38);
const sf::Vector2i Block::footprint(2, 2);

void init_blocks() {
	Block::shape.setSize(Block::size);
	Block::shape.setFillColor(sf::Color::Magenta);
}

Block::Block(const sf::Vector2i& tile) : Entity() {
	tile_rect.left = tile.x;
	tile_rect.top = tile.y;
	tile_rect.width = footprint.x;
	tile_rect.height = footprint.y;
	sf::Vector2f center((tile.x + footprint.x * 0.5f) * tile_size.x, (tile.y + footprint.y * 0.5f) * tile_size.y);
	position_rect.left = center.x - (size.x / 2);
	position_rect.top = center.y - (size.y / 2);
	position_rect.width = size.x;
	position_rect.height = size.y;
	all_blocks.push_back(this);
	for (int i = 0; i < footprint.x; i++) {
		for (int j = 0; j < footprint.y; j++) {
			sf::Vector2i footprint_tile(tile.x + i, tile.y + j);
			my_map.set_tile(tile, this);
		}
	}
}

void Block::draw() {
	sf::Vector2f pos(position_rect.left, position_rect.top);
	shape.setPosition(world_pos_to_screen_pos(pos));
	window.draw(shape);
}