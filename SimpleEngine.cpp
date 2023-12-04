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
#include <fstream>
#include <iostream>
#include "SDL.h"


#pragma comment (lib,"SDL2")
#pragma comment (lib,"SDL2main")
class SpawnActor;
class AActor;

SimpleEngine* SimpleEngine::Instance = nullptr;
int SimpleEngine::KeyCode = 0;


SimpleEngine::SimpleEngine()
{
	GameMode = nullptr;
	GameState = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	Init();
}

SimpleEngine::~SimpleEngine()
{
	Term();

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
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
		DeltaSeconds = SDL_GetTicks64() - LastTime;
		LastTime = SDL_GetTicks();
		Input();
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			IsRunning = false;
			break;

		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
			break;
		}
		Tick();
		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(GEngine->MyRenderer);

		Render();
		SDL_RenderPresent(GEngine->MyRenderer);
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

	int Y = 0;

	std::string line;
	std::ifstream file(Filename);
	if (file.is_open()) {
		while (getline(file, line)) {
			for (int X = 0; X < line.length(); X++)
			{
				LoadActor(X, Y, line[X]);

			}
			Y++;
		}
		file.close();
	}



	
	GetWorld()->SortRenderOrder();
	GameMode = new AGameMode();
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameMode);
	GetWorld()->SpawnActor(GameState);
};
void SimpleEngine::Input()
{
	SDL_PollEvent(&MyEvent);
}

void SimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

void SimpleEngine::LoadActor(int NewX, int NewY, char Actor)
{
	if (Actor == '*')
	{
		//wall
		GetWorld()->SpawnActor(new AWall(NewX, NewY));
	}
	else if (Actor == 'P')
	{
		//Player
		GetWorld()->SpawnActor(new APlayer(NewX, NewY));
	}
	else if (Actor == 'M')
	{

		//Monster
		GetWorld()->SpawnActor(new AMonster(NewX, NewY));
	}
	else if (Actor == 'G')
	{

		//Goal
		GetWorld()->SpawnActor(new AGoal(NewX, NewY));
	}

	else if (Actor == ' ')
	{
		GetWorld()->SpawnActor(new AFloor(NewX, NewY));
	}
}

