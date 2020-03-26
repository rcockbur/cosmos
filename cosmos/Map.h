//#pragma once
#include <vector>
using namespace std;

class Map {
	int size[2];
	vector<vector<int> > tiles;
public:
	Map(int x, int y);
	void set_tile(int x, int y, bool val);
	int get_tile(int x, int y);
	void draw();
};
