#pragma once
#include <SFML/System/Vector2.hpp>
#include <list>
#include "unit.h"

class Unit;

class Ability {
public:
	virtual bool execute() = 0;
};

class Move : public Ability {
public:
	std::list<sf::Vector2i> path;
	Unit& unit;

	Move(Unit& unit, const sf::Vector2i& target_tile);
	bool execute();
};