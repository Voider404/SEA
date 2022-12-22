#pragma once
#include "Actor.h"
class AIPlayer : public Actor
{
public:
	int lastRes = 0;
	int finishingOff = 0;
	int hitCount = 0;
	int x = 4, y = 4;
	void shot(Field& enemyField);
	Point getNextPoint(Field& enemyField);
};