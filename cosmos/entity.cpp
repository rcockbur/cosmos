#include "entity.h"
#include "utility.h"
#include <SFML/System/Vector2.hpp>

extern sf::Vector2f tile_size;
Entity * selected_entity;

int Entity::entity_id_index;

void init_entities() {
	selected_entity = nullptr;
	Entity::entity_id_index = 0;
}

Entity::Entity() : position_rect(), entity_id(entity_id_index) {
	++entity_id_index;
}
