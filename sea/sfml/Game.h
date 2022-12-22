#pragma once
#include<iostream>
#include "AIPlayer.h"
#include "Player.h"
#include <time.h>

class Game
{
public:
	AIPlayer ai;
	Player player;
	int turn = rand() % 2;

	void initGame();
	void makeStep(int x, int y);
	// 0 - не окончена
	// 1 - выиграл компьютер
	// 2 - выиграл игрок
	int gameOver();
	void debugPrint();
};