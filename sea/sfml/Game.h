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
	// 0 - �� ��������
	// 1 - ������� ���������
	// 2 - ������� �����
	int gameOver();
	void debugPrint();
};