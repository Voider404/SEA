#include "Actor.h"

bool Actor::getRandBoll()
{
	return rand() % 2 == 0;
}

void Actor::randFillField()
{
	bool a = true;
	while (field.ships.size() < 1)
	{
		a = getRandBoll();
		if (a)
			field.addShip(Point(rand() % 7, rand() % 10), a, 4);
		else
			field.addShip(Point(rand() % 10, rand() % 7), a, 4);
	}
	while (field.ships.size() < 3)
	{
		a = getRandBoll();
		if (a)
			field.addShip(Point(rand() % 8, rand() % 10), a, 3);
		else
			field.addShip(Point(rand() % 10, rand() % 8), a, 3);
	}
	while (field.ships.size() < 6)
	{
		a = getRandBoll();
		if (a)
			field.addShip(Point(rand() % 9, rand() % 10), a, 2);
		else
			field.addShip(Point(rand() % 10, rand() % 9), a, 2);
	}
	while (field.ships.size() < 10)
	{
		a = getRandBoll();
		if (a)
			field.addShip(Point(rand() % 10, rand() % 10), a, 1);
		else
			field.addShip(Point(rand() % 10, rand() % 10), a, 1);
	}
	initOutOfRange();
}

void Actor::initOutOfRange()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.fieldData[i][j] == 3)
				field.fieldData[i][j] = 0;
		}
	}
	--field.fieldData;
	for (int i = 0; i < 12; i++)
		field.fieldData[i]--;
	for (int i = 0; i < 12; i++)
	{
		field.fieldData[0][i] = -1;
		field.fieldData[11][i] = -1;
		field.fieldData[i][0] = -1;
		field.fieldData[i][11] = -1;
	}
	for (int i = 0; i < 12; i++)
		field.fieldData[i]++;
	++field.fieldData;
}