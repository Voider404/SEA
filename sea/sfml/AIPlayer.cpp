#include "AIPlayer.h"
#include <time.h>

Point AIPlayer::getNextPoint(Field& enemyField)
{
	if (finishingOff)
	{
		for (int i = 0; i < 10; i++)//Добивание, если погибших клеток больше одной
		{
			for (int j = 0; j < 10; j++)
			{
				if (enemyField.fieldData[i][j] == 2)
				{
					if (enemyField.fieldData[i + 1][j] == 2)
					{
						if (enemyField.fieldData[i + 2][j] == 2)
						{
							if (enemyField.fieldData[i + 3][j] == 0 || enemyField.fieldData[i + 3][j] == 1)
							{
								return Point(i + 3, j);
							}
						}
						else if (enemyField.fieldData[i + 2][j] == 0 || enemyField.fieldData[i + 2][j] == 1)
						{
							return Point(i + 2, j);
						}
					}
					if (enemyField.fieldData[i][j + 1] == 2)
					{
						if (enemyField.fieldData[i][j + 2] == 2)
						{
							if (enemyField.fieldData[i][j + 3] == 0 || enemyField.fieldData[i][j + 3] == 1)
							{
								return Point(i, j + 3);
							}
						}
						else if (enemyField.fieldData[i][j + 2] == 0 || enemyField.fieldData[i][j + 2] == 1)
						{
							return Point(i, j + 2);
						}
					}
					if (enemyField.fieldData[i - 1][j] == 2)
					{
						if (enemyField.fieldData[i - 2][j] == 2)
						{
							if (enemyField.fieldData[i - 3][j] == 0 || enemyField.fieldData[i - 3][j] == 1)
							{
								return Point(i - 3, j);
							}
						}
						else if (enemyField.fieldData[i - 2][j] == 0 || enemyField.fieldData[i - 2][j] == 1)
						{
							return Point(i - 2, j);
						}
					}
					if (enemyField.fieldData[i][j - 1] == 2)
					{
						if (enemyField.fieldData[i][j - 2] == 2)
						{
							if (enemyField.fieldData[i][j - 3] == 0 || enemyField.fieldData[i][j + 3] == 1)
							{
								return Point(i, j - 3);
							}
						}
						else if (enemyField.fieldData[i][j - 2] == 0 || enemyField.fieldData[i][j + 2] == 1)
						{
							return Point(i, j - 2);
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++)//добивание, если известно только про одну подбитую клетку
		{
			for (int j = 0; j < 10; j++)
			{
				if (enemyField.fieldData[i][j] == 2)
				{
					if (enemyField.fieldData[i + 1][j] == 0 || enemyField.fieldData[i + 1][j] == 1)
					{
						return Point(i + 1, j);
					}
					if (enemyField.fieldData[i][j + 1] == 0 || enemyField.fieldData[i][j + 1] == 1)
					{
						return Point(i, j + 1);
					}
					if (enemyField.fieldData[i - 1][j] == 0 || enemyField.fieldData[i - 1][j] == 1)
					{
						return Point(i - 1, j);
					}
					if (enemyField.fieldData[i][j - 1] == 0 || enemyField.fieldData[i][j - 1] == 1)
					{
						return Point(i, j - 1);
					}
				}
			}
		}
	}
	return Point(rand() % 10, rand() % 10);
}

void AIPlayer::shot(Field& enemyField) // действие "ИИ" при попадании в клетку
{
	while (enemyField.ships.size() > 0)
	{
		lastRes = enemyField.getShot(getNextPoint(enemyField));
		if (lastRes == 0)
		{
			break;
		}
		if (lastRes == 1)
		{
			finishingOff++; //добивание
		}
		if (lastRes == 2)
		{
			finishingOff = 0; // без добивания
		}
	}
}
