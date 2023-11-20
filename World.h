#pragma once
#include <vector>
class AActor;
class UWorld
{
public:
	UWorld();
	virtual ~UWorld();
	void SpawnActor(AActor* newActor);
	void Tick(int KeyCode);
	void Render();
protected:
	std::vector<AActor*> Actors;

};

