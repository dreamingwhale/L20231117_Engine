#include "Goal.h"

AGoal::AGoal()
{
	X = 9;
	Y = 9;
	Shape = 'G';
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AGoal::~AGoal()
{
}
