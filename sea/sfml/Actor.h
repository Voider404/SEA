#pragma once
#include "Field.h"
class Actor
{
public:
	Field field;
	
	bool getRandBoll();
	void randFillField();
	void initOutOfRange();
	virtual void shot(Field& enemyField) = 0;
};