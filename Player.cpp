#include "Player.h"
#include <iostream>
#include "SimpleEngine.h"
#include "World.h"
#include "Goal.h"
#include "GameState.h"

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
			continue;//같다면 밑의 로직을 실행하지 않고 for문을 실행. 그냥 넘긴다.
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

void APlayer::Tick()
{
	//AActor::Tick(KeyCode);				//Super가 원래 c++에서는 존재하지 않음. 언리얼에는 존재
	__super::Tick();						//visual studio 전용 문법
	int KeyCode = SimpleEngine::KeyCode;	//static으로 keycode를 던져넣고 받기
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
	if (KeyCode == 27)
	{
		GEngine->Stop();
	}

	//골이 여러개일 경우 문제가 있음
	AGoal* MyGoal = nullptr;
	for (auto Actor : GEngine->GetWorld()->GetAllActors())
	{
		MyGoal = dynamic_cast<AGoal*>(Actor);
		if (MyGoal &&
			MyGoal->GetX() == X &&
			MyGoal->GetY() == Y)
		{
			SimpleEngine::GetGameState()->IsNextLevel = true;
			GEngine->Stop();
			break;
		}
	}


}
