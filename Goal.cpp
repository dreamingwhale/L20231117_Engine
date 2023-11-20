#include "Goal.h"

AGoal::AGoal()
{
	X = 9;
	Y = 9;
	Shape = 'G';
	SortOrder = 200;
}

AGoal::AGoal(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
}

AGoal::~AGoal()
{
}
