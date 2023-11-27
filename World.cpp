#include "World.h"
#include "Actor.h"
#include <algorithm>

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

void UWorld::Tick()
{
	for (auto Actor : Actors)	//(const auto& Actor : Actors)값을 복사하지 말고 참조만 하라
	{

		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SortRenderOrder()
{
	std::sort(Actors.begin(),
		Actors.end(),
		[](const AActor* LHS, const AActor* RHS) {
			return LHS->SortOrder < RHS->SortOrder;
		});
}
