#pragma once
#include<ostream>
#include "Ship.h"
using namespace std;
class Field
{
public:
	vector<Ship> ships;

	const int n = 10;
	//0 - пусто
	//1 - живая палуба
	//2 - мертвая палуба
	//3 - промах
	int** fieldData;
	Field();
	~Field();

	bool addShip(Point start, bool horizontal = true, int size = 1);
	void deleteShip(Point point);
	int getShot(Point coords); //0 - пусто, 1 - живая палуба, 2 - мертвая палуба
	void drawShip(Ship ship, int cellType);
	void eraseShip(Ship ship);
	friend ostream& operator<<(ostream& stream, const Field& field);
	bool isFull();
};

