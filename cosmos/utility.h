#pragma once
#include <SFML/System/Vector2.hpp>

sf::Vector2i world_pos_to_tile(const sf::Vector2f& world_pos);
sf::Vector2f tile_center_to_world_pos(const sf::Vector2i& tile);

sf::Vector2i screen_pos_to_tile(sf::Vector2f& screen_pos);
sf::Vector2f tile_to_screen_pos(sf::Vector2i& tile);

sf::Vector2f screen_pos_to_world_pos(const sf::Vector2f& screen_pos);
sf::Vector2f world_pos_to_screen_pos(const sf::Vector2f& world_pos);

//void 