#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "ability.h"
#include "entity.h"

using namespace std;

void init_units();

class Unit : public Entity {
public:
	static sf::RectangleShape shape;
	static const sf::Vector2f size;
	
	vector<Ability*> ability_queue;

	Unit(const sf::Vector2i& tile);
	void move_by(const sf::Vector2f&);
	void update();
	void queue_up_move(const sf::Vector2i tile);
	void draw();
};

