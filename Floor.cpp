#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 1;
}

AFloor::AFloor(int NewX, int NewY, char NewShape, int newSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = newSortOrder;
}

AFloor::~AFloor()
{
}
