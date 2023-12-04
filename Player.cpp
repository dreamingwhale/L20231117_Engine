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

void APlayer::Tick()
{
	//AActor::Tick(KeyCode);				//Super�� ���� c++������ �������� ����. �𸮾󿡴� ����
	__super::Tick();						//visual studio ���� ����
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
