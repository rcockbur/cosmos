#pragma once
#include <SFML/System/Vector2.hpp>

class Unit;

class Ability {
public:
	virtual bool execute() = 0;
};

class Move : Ability {
public:
	Move(Unit& unit, sf::Vector2i& target_tile);
	bool execute();
};