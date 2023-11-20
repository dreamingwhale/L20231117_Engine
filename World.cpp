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
	for (auto Actor : Actors)	//(const auto& Actor : Actors)���� �������� ���� ������ �϶�
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
