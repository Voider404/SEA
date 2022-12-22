#pragma once
#include<vector>
#include "Point.h"
using namespace std;
class Ship
{
public:
	vector<Point> cells;
	Ship(Point startCell, bool horizontal = true, int size = 1);
	Ship(const Ship& ship);
	~Ship();

	bool isAlive();
	bool getShot(Point coords);
	bool pointBelongs(Point coords);
};