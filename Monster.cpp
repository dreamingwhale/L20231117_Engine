#include "Monster.h"

AMonster::AMonster()
{
	X = 5;
	Y = 5;
	Shape = 'M';
	SortOrder = 300;
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
}

AMonster::~AMonster()
{
}
