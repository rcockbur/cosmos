#include "block_manager.h"
#include "block.h"
#include <SFML/System/Vector2.hpp>

std::vector <Block *> all_blocks;

Block * new_block(const sf::Vector2i& tile) {
	all_blocks.push_back(new Block(tile));
	return all_blocks.back();
}