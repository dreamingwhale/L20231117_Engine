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
	SpriteIndex = 0;
	SpriteDirection = 0;
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
	SpriteIndex = 0;
	SpriteDirection = 0;

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

	ElaspedTime += GEngine->GetWorldDeltaSeconds();
	if (ElaspedTime >= ProcessTime)
	{
		SpriteIndex++;
		SpriteIndex = SpriteIndex % SpriteSizeX;
		ElaspedTime = 0;
	}

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
			SpriteDirection = 0;

		}
		//GEngine->GetAllActors();
	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{

			X++;
			SpriteDirection = 1;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{

			Y--;
			SpriteDirection = 2;
		}
	}
	if (KeyCode == SDLK_s)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
			SpriteDirection = 3;
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

void APlayer::Render()
{
	__super::Render();

	

	SDL_RenderCopy(GEngine->MyRenderer
		, MyTexture
		, new SDL_Rect{
			SpriteIndex * 256 / 5
			, SpriteDirection * 256 / 5
			, MySurface->w / SpriteSizeX
			, MySurface->h / SpriteSizeY
			}
		, new SDL_Rect{ X * Size,Y * Size,Size,Size
		});

}
