#pragma once
#include "Actor.h"
class Player :
	public Actor
{
public:
	void shot(Field& enemyField);
};