#include "Monster.h"

AMonster::AMonster()
{
	X = 5;
	Y = 5;
	Shape = 'M';
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AMonster::~AMonster()
{
}
