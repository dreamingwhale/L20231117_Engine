#include "SimpleEngine.h"
#include "World.h"
#include "Player.h"
#include <conio.h>
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"
#include "GameMode.h"
#include "GameState.h"

class SpawnActor;
class AActor;

SimpleEngine* SimpleEngine::Instance = nullptr;
int SimpleEngine::KeyCode = 0;

SimpleEngine::SimpleEngine()
{
	GameMode = nullptr;
	GameState = nullptr;
	Init();
}

SimpleEngine::~SimpleEngine()
{

	Term();
}

void SimpleEngine::Init()
{
	World = new UWorld;
	IsRunning = true;
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{

		Input();
		//물리처리
		Tick();
		//물리그림
		system("cls");
		Render();
	}
}

void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
	GameMode = nullptr;
	GameState = nullptr;
	IsRunning = false;
	delete World;
}

void SimpleEngine::LoadLevel(std::string Filename)
{
	//Save
	//Memory -> Disk : Sirialize

	//Load
	//Disk -> Memory : Desirialize
	//file로 바꿀것

	//singletone의 경우 



	std::string Map[10] =
	{
	"*****************",
	"*P              *",
	"*               *",
	"*               *",
	"*       M       *",
	"*               *",
	"*               *",
	"*               *",
	"*       G       *",
	"*****************"
	};

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 18; ++X)
		{
			if (Map[Y][X] == '*')
			{
				//wall
				GetWorld()->SpawnActor(new AWall(X, Y));
			}
			else if (Map[Y][X] == 'P')
			{
				//Player
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Map[Y][X] == 'M')
			{

				//Monster
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Map[Y][X] == 'G')
			{

				//Goal
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}

			else if (Map[Y][X] == ' ')
			{

			}
			GetWorld()->SpawnActor(new AFloor(X, Y));
		}

	}
	GetWorld()->SortRenderOrder();
	GameMode = new AGameMode();
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameMode);
	GetWorld()->SpawnActor(GameState);
};
void SimpleEngine::Input()
{
	KeyCode = _getch();
}

void SimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

