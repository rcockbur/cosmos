#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

void init_blocks();

class Block : public Entity {
public:
	static sf::RectangleShape shape;
	static const sf::Vector2f size;
	static const sf::Vector2i footprint;

	sf::IntRect tile_rect;
	
	Block(const sf::Vector2i& tile);
	void draw();
};
