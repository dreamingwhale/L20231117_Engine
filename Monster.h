#pragma once
#include "Actor.h"
class AMonster :
	public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M', int NewSortOrder = 300, SDL_Color NewColor = SDL_Color{ 255,0,0,0 });
	virtual ~AMonster();

	bool IsCollide(int NewX, int NewY);
	virtual void Tick() override;
	Uint32 ProcessTime;
	Uint32 ElaspedTime;
	SDL_Surface* Image;
	SDL_Texture* Texture;
};

enum class EMonsterDirection
{
	Left = 0,
	Right = 1,
	Down,
	Up

};