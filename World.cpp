#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::SpawnActor(AActor* newActor)
{
	if (newActor)
	{
		Actors.push_back(newActor);
	}
}

void UWorld::Tick(int KeyCode)
{
	for (auto Actor : Actors)	//(const auto& Actor : Actors)값을 복사하지 말고 참조만 하라
	{
		Actor->Tick(KeyCode);
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}
