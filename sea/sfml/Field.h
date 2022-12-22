#pragma once
#include<ostream>
#include "Ship.h"
using namespace std;
class Field
{
public:
	vector<Ship> ships;

	const int n = 10;
	//0 - �����
	//1 - ����� ������
	//2 - ������� ������
	//3 - ������
	int** fieldData;
	Field();
	~Field();

	bool addShip(Point start, bool horizontal = true, int size = 1);
	void deleteShip(Point point);
	int getShot(Point coords); //0 - miss, 1 - shot, 2 - deadshot
	void drawShip(Ship ship, int cellType);
	void eraseShip(Ship ship);
	friend ostream& operator<<(ostream& stream, const Field& field);
	bool isFull();
};
