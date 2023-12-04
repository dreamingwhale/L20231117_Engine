#include "Monster.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "World.h"
#include "SimpleEngine.h"
#include "Player.h"
#include "GameMode.h"
#include "GameState.h"

AMonster::AMonster()
{
	X = 5;
	Y = 5;
	Shape = 'M';
	SortOrder = 300;
	srand((unsigned int)time(NULL));
	bCollide = false;
}

bool AMonster::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
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

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor )
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
	Color = NewColor;
}


AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	__super::Tick();
	
	
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		APlayer* MyPlayer = dynamic_cast<APlayer*>(Actor);
		if (MyPlayer &&
			MyPlayer->GetX() == X &&
			MyPlayer->GetY() == Y)
		{
			SimpleEngine::GetGameState()->IsGameOver = true;
			//break;
			return;
		}

	}
	int Direction = rand() % 4;
	if (Direction == (int)EMonsterDirection::Left)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	};
	if (Direction == (int)EMonsterDirection::Right)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	};
	if (Direction == (int)EMonsterDirection::Up)
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	};
	if (Direction == (int)EMonsterDirection::Down)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	};

	
}
