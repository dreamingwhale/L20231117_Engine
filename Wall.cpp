#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	SortOrder = 100;
	bCollide = true;
}

AWall::AWall(int NewX, int NewY, char NewShape,int NewSortOrder, SDL_Color NewColor)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
	bCollide = true;
	Color = NewColor;
}

int AWall::GetX()
{
	return X;
}

int AWall::GetY()
{
	return Y;
}


AWall::~AWall()
{
}
