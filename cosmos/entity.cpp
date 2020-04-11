#include "entity.h"
#include "utility.h"
#include <SFML/System/Vector2.hpp>

extern sf::Vector2f tile_size;
Entity * selected_entity_ptr;

int Entity::entity_id_index;

void init_entities() {
	selected_entity_ptr = nullptr;
	Entity::entity_id_index = 0;
}

Entity::Entity() : position_rect(), entity_id(entity_id_index) {
	++entity_id_index;
}

void Entity::select() {
	if (selected_entity_ptr != nullptr) {
		(*selected_entity_ptr).deselect();
	}
	is_selected = true;
	selected_entity_ptr = this;
}
void Entity::deselect() {
	(*selected_entity_ptr).is_selected = false;
	selected_entity_ptr = nullptr;
}