#include "utility.h"
#include <SFML/System/Vector2.hpp>

extern sf::Vector2f grid_size;
extern sf::Vector2f tile_size;
extern sf::Vector2f camera_pos;
extern sf::Vector2i tile_count;

sf::Vector2f screen_pos_to_world_pos(const sf::Vector2f& screen_pos) {
	return screen_pos + camera_pos;
}
sf::Vector2f world_pos_to_screen_pos(const sf::Vector2f& world_pos) {
	return world_pos - camera_pos;
}

sf::Vector2i world_pos_to_tile(const sf::Vector2f& world_pos) {
	return sf::Vector2i((int)(world_pos.x / tile_size.x), (int)(world_pos.y / tile_size.y));
}

sf::Vector2f tile_center_to_world_pos(const sf::Vector2i& tile) {
	return sf::Vector2f(((float)tile.x + 0.5) * (float)tile_size.x, ((float)tile.y + 0.5) * (float)tile_size.y);
}

sf::Vector2i screen_pos_to_tile(sf::Vector2f& screen_pos);
sf::Vector2f tile_to_screen_pos(sf::Vector2i& tile);