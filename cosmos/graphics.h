#pragma once
#include "unit.h"
#include "map.h"

void init_graphics();
void init_text();
void draw_units();
void draw_blocks();
void draw_map(const Map& map);
void draw_selected();