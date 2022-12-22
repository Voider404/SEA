#include "Point.h"

bool Point::operator==(Point& point)
{
	return x == point.x && y == point.y;
}
