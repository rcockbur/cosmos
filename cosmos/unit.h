#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

void init_units();

class Entity {
public:
	sf::Vector2f position;
};

class Block : public Entity {
public:
	static sf::RectangleShape shape;
	static const float radius;
	sf::Vector2i tile;
	Block(const sf::Vector2i& tile);
	void draw();
};

class Unit : public Entity {
public:
	static sf::RectangleShape shape;
	static const float radius;
	Unit(const sf::Vector2f& tile);
	void move_by(const sf::Vector2f&);
	void draw();
};