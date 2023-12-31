#include "SDL.h"
#include <iostream>
#pragma once
#include <vector>
class AActor
{
public:

	AActor();
	AActor(int NewX, int NewY);
	virtual ~AActor();

	//virtual void BeginPlay()=0;를 통해 순수 가상 함수로 구현할 수 있다. => 재정의해서 구현해라라는 의미
	//c++는 다중 상속이 가능하기에 인터페이스를 따로 구현할 필요가 없다. 하지만 
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
	//accessor
	int GetX() const { return X; };
	int GetY() const { return Y; };

	inline void SetX(int NewX) { X = NewX; };
	inline void SetY(int NewY) { Y = NewY; };

	//순서 정렬을 위한 비교연산자 재정의
	
	virtual bool operator<(const AActor& RHS) const
	{
		return this->SortOrder < RHS.SortOrder;
	}
	
	virtual bool operator>(const AActor& RHS) const
	{
		return this->SortOrder > RHS.SortOrder;
	}

	bool bIsSprite;
	int SpriteSizeX;
	int SpriteSizeY;

	int SortOrder;
	bool bCollide;
	SDL_Color Color;
	Uint16 Size;
	SDL_Surface* MySurface;
	SDL_Texture* MyTexture;
	virtual void LoadBMP(std::string Filename, SDL_Color Colorkey = SDL_Color{255,255,255,0});


protected:
	int X;
	int Y;

	char Shape;
};
