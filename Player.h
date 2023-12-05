#pragma once
#include "Actor.h"
#include "Wall.h" 
class APlayer : public AActor
{

public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P', int NewSortOrder = 400, SDL_Color NewColor = SDL_Color{ 0,255,0,0 });
	virtual ~APlayer();

	bool IsCollide(int NewX, int NewY);
	virtual void Tick() override;
	Uint32 ProcessTime;
	Uint32 ElaspedTime;
	Uint8 SpriteIndex;
	Uint8 SpriteDirection;

	virtual void Render() override;
};

