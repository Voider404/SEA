#include "Game.h"

void Game::initGame()
{
	ai.randFillField();
}

void Game::makeStep(int x, int y)
{
	if (gameOver() != 0)
	{
		return;
	}
	if (ai.field.getShot(Point(x, y)) == 0)
	{
		if (gameOver() != 0)
		{
			return;
		}
		ai.shot(player.field);
	}
}

int Game::gameOver()
{
	if (player.field.ships.size() == 0) // при победе игрока
	{
		return 1;
	}
	if (ai.field.ships.size() == 0) // при победе ИИ
	{
		return 2;
	}
	return 0;
}

void Game::debugPrint()
{
	system("cls");
	cout << ai.field << endl;
	cout << player.field << endl;
}
