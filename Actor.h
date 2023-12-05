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

	//virtual void BeginPlay()=0;�� ���� ���� ���� �Լ��� ������ �� �ִ�. => �������ؼ� �����ض��� �ǹ�
	//c++�� ���� ����� �����ϱ⿡ �������̽��� ���� ������ �ʿ䰡 ����. ������ 
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
	//accessor
	int GetX() const { return X; };
	int GetY() const { return Y; };

	inline void SetX(int NewX) { X = NewX; };
	inline void SetY(int NewY) { Y = NewY; };

	//���� ������ ���� �񱳿����� ������
	
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
