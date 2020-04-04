#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "ability.h"

using namespace std;

void init_units();

class Entity {
public:
	sf::Vector2f position;
	sf::Vector2i tile;
};

class Block : public Entity {
public:
	static sf::RectangleShape shape;
	static const float radius;
	
	Block(const sf::Vector2i& tile);
	void draw();
};

class Unit : public Entity {
public:
	static sf::RectangleShape shape;
	vector<Ability*> ability_queue;
	static const float radius;
	Unit(const sf::Vector2i& tile);
	void move_by(const sf::Vector2f&);
	void update();
	void queue_up_move(const sf::Vector2i tile);
	void draw();
};

