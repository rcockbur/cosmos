#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

void init_entities();

class Entity {
	bool is_selected;
public:
	sf::FloatRect position_rect;
	
	Entity();
	void select();
};