#include "Field.h"

Field::Field()
{
	fieldData = new int*[n + 2]{ 0 };
	for (int i = 0; i < n + 2; ++i)
	{
		fieldData[i] = new int[n + 2]{ 0 };
		++fieldData[i];
	}
	++fieldData;
}

Field::~Field()
{
	--fieldData;
	for (int i = 0; i < n + 2; ++i)
	{
		--fieldData[i];
		delete[] fieldData[i];
	}
	delete fieldData;
}

bool Field::addShip(Point start, bool horizontal, int size)
{
	if (start.x < 0 || start.y < 0 || start.x >= 10 || start.y >= 10)
	{
		return false;
	}

	int left = start.y;
	int top = start.x;
	int right = start.y;
	int bottom = start.x;
	if (!horizontal)
	{
		right += size;
		for (int i = left; i < right; i++)
			if (fieldData[top][i] != 0 || i > 9)
				return false;
	}
	else
	{
		bottom += size;
		for (int j = top; j < bottom; j++)
			if (fieldData[j][left] != 0 || j > 9)
				return false;
	}

	ships.push_back(Ship(start, horizontal, size));
	drawShip(ships[ships.size() - 1], 1);

	return true;
}

void Field::deleteShip(Point point)
{
	for (int i = 0; i < ships.size(); ++i)
	{
		if (ships[i].pointBelongs(point))
		{
			eraseShip(ships[i]);
			ships.erase(ships.begin() + i);
		}
	}
}

int Field::getShot(Point coords)
{
	for (int i = 0; i < ships.size(); ++i)
	{
		if (fieldData[coords.x][coords.y] > 1)
		{
			return 1;
		}
		if (ships[i].getShot(coords))
		{
			if (!ships[i].isAlive())
			{
				drawShip(ships[i], 2); //корабль убит
				ships.erase(ships.begin() + i);
				return 2;
			}
			else
			{
				fieldData[coords.x][coords.y] = 2; //корабль ранен
				return 1;
			}
		}
	}
	fieldData[coords.x][coords.y] = 3; //по клетке промахнулись
	return 0;
}

void Field::drawShip(Ship ship, int cellType)
{
	for (int i = ship.cells[0].x - 1; i <= ship.cells[ship.cells.size() - 1].x + 1; ++i)
	{
		for (int j = ship.cells[0].y - 1; j <= ship.cells[ship.cells.size() - 1].y + 1; ++j)
		{
			fieldData[i][j] = 3;
		}
	}
	for (int i = 0; i < ship.cells.size(); ++i)
	{
		fieldData[ship.cells[i].x][ship.cells[i].y] = cellType;
	}
}

void Field::eraseShip(Ship ship)
{
	for (int i = ship.cells[0].x - 1; i <= ship.cells[ship.cells.size() - 1].x + 1; ++i)
	{
		for (int j = ship.cells[0].y - 1; j <= ship.cells[ship.cells.size() - 1].y + 1; ++j)
		{
			fieldData[i][j] = 0;
		}
	}
}

ostream& operator<<(ostream& stream, const Field& field)
{
	stream << "FIELD:" << endl;
	for (int i = 0; i < field.n; ++i)
	{
		for (int j = 0; j < field.n; ++j)
		{
			switch (field.fieldData[i][j])
			{
			case 0: stream << '.'; break;
			case 1: stream << 'O'; break;
			case 2: stream << 'X'; break;
			case 3: stream << '!'; break;
			}
		}
		stream << endl;
	}
	return stream;
}

bool Field::isFull()
{
	return (ships.size() == 10);
}