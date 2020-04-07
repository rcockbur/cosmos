#include "entity.h"
#include "utility.h"
#include <SFML/System/Vector2.hpp>

extern sf::Vector2f tile_size;

Entity * selected_entity;

void init_entities() {
	selected_entity = nullptr;
}

Entity::Entity() : position_rect() {}

void Entity::select() {}