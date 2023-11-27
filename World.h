#pragma once
#include <vector>

class AActor;
class UWorld
{
public:
	UWorld();
	virtual ~UWorld();
	void SpawnActor(AActor* newActor);
	void Tick();
	void Render();

	void SortRenderOrder();
	const std::vector<AActor*>& GetAllActors()
	{
		return Actors;
	}
protected:
	std::vector<AActor*> Actors;

};

