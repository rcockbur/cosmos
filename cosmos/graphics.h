#pragma once
#include "unit.h"
#include "map.h"

void init_graphics();
void draw_unit(const Unit& unit);
void draw_block(const Block& block);
void draw_map(const Map& map);