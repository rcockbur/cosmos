#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

void init_entities();

class Entity {
	
	
public:
	static int entity_id_index;
	bool is_selected;
	int entity_id;
	sf::FloatRect position_rect;
	Entity();
	virtual void draw() = 0;
};