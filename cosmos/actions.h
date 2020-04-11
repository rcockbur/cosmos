#pragma once
#include <SFML/System/Vector2.hpp>
#include "unit.h"

void try_spawn_unit(const sf::Vector2i& tile);

void try_spawn_block(const sf::Vector2i& tile);

void select_entity(const sf::Vector2f& world_pos);

void move_selected_by(const sf::Vector2f& vec);