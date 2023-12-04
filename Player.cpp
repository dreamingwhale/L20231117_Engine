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

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	Color = NewColor;
	LoadBMP("Data/Player.bmp", SDL_Color{ 255,0,255,0 });
	bIsSprite = true;
	SpriteSizeX = 5;
	SpriteSizeY = 5;

	ProcessTime = 500;
	ElaspedTime = 0;
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
	int KeyCode = GEngine->MyEvent.key.keysym.sym;

	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		return;
	}
	if (SimpleEngine::GetGameState()->IsGameOver)
	{
		return;
	}

	if (KeyCode == SDLK_a)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;

		}
		//GEngine->GetAllActors();
	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{

			X++;

		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{

			Y--;

		}
	}
	if (KeyCode == SDLK_s)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == SDLK_ESCAPE)
	{
		GEngine->Stop();
	}

	ElaspedTime += GEngine->GetWorldDeltaSeconds();
	if (ElaspedTime <= ProcessTime)
	{
		return;
		if (KeyCode == SDLK_UNKNOWN)
		{
			if (MySurfaceW < 6)
			{
				MySurfaceW += 1;
				MySurfaceH += 1;

			}
			else
			{
				MySurfaceW = 1;
				MySurfaceH = 1;

			}
		}
	}
	else
	{
		ElaspedTime = 0;
	}


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
