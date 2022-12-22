#pragma once
class Point
{
public:
	int x;
	int y;
	bool state;
	Point(int x = 0, int y = 0, bool state = true) :x(x), y(y), state(state) {}
	Point(const Point& point) : x(point.x), y(point.y), state(point.state) {}

	bool operator==(Point& point);
};