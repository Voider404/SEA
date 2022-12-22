#include "Ship.h"

Ship::Ship(Point startCell, bool horizontal, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (horizontal)
		{
			cells.push_back(Point(startCell.x + i, startCell.y, true));
		}
		else
		{
			cells.push_back(Point(startCell.x, startCell.y + i, true));
		}
	}
}

Ship::Ship(const Ship& ship)
{
	for (int i = 0; i < ship.cells.size(); ++i)
	{
		cells.push_back(ship.cells[i]);
	}
}

Ship::~Ship()
{
	cells.clear();
}

bool Ship::isAlive()
{
	for (int i = 0; i < cells.size(); ++i)
	{
		if (cells[i].state)
		{
			return true;
		}
	}
	return false;
}

bool Ship::getShot(Point coords) // проверка на подбитие
{
	for (int i = 0; i < cells.size(); ++i)
	{
		if (cells[i] == coords)
		{
			cells[i].state = false;
			return true;
		}
	}
	return false;
}

bool Ship::pointBelongs(Point coords)
{
	for (int i = 0; i < cells.size(); ++i)
	{
		if (cells[i] == coords)
		{
			return true;
		}
	}
	return false;
}