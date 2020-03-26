#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

sf::RenderWindow window(sf::VideoMode(400, 400), "cosmos");
sf::CircleShape shape;
float shape_size = 10.;


int main()
{
	shape.setRadius(shape_size);
	shape.setFillColor(sf::Color::Green);

	Map map(6,4);
	map.set_tile(1, 1, false);
	map.set_tile(2, 1, false);
	map.set_tile(3, 1, false);

	while (window.isOpen()) {
		sf::Clock clock;
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			// window closed
			case sf::Event::Closed:
				window.close();
				break;
			// key pressed
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape){
					window.close();
					break;
				}
				if (event.key.code == sf::Keyboard::Q) {
					window.close();
					break;
				}
				break;
			// we don't process other types of events
			default:
				break;
			}
		}

		window.clear();
		map.draw();
		window.display();
	}
	return 0;
}