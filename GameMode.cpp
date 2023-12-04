#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"
#include "SimpleEngine.h"
#include "World.h"
#include <iostream>
#include <vector>
#include "GameState.h"

AGameMode::AGameMode()
{
	SortOrder = 1000;
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor::Tick();
	if (SimpleEngine::GetGameState()->IsNextLevel)
	{
		std::cout << "Mission Completed" << std::endl;
		GEngine->LoadLevel("Data/level02.smap");
	}
	if (SimpleEngine::GetGameState()->IsGameOver)
	{
		std::cout << "Mission Failed" << std::endl;
		GEngine->Stop();
	}
	
}
