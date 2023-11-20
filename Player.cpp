#include "Player.h"
#include <iostream>
#include "SimpleEngine.h"
#include "World.h"
APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 400;
	bCollide = false;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
}

APlayer::~APlayer()
{
}



bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;//���ٸ� ���� ������ �������� �ʰ� for���� ����. �׳� �ѱ��.
		}
		if (Actor->GetX() == NewX &&
			Actor->GetY() == NewY &&
			Actor->bCollide == true)
		{
			return true;
		}
	}
	return false;
}

void APlayer::Tick(int KeyCode)
{
	//AActor::Tick(KeyCode);	//Super�� ���� c++������ �������� ����. �𸮾󿡴� ����
	__super::Tick(KeyCode);		//visual studio ���� ����

	if (KeyCode == 'A' || KeyCode == 'a')
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;

		}
		//GEngine->GetAllActors();
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{

			X++;

		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{

			Y--;

		}
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		if (!IsCollide(X, Y + 1))
		{

			Y++;

		}
	}
}
