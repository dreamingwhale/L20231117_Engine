#include "Actor.h"
#include <windows.h>
#include <iostream>
#include "SimpleEngine.h"
#include "Monster.h"
AActor::AActor() :
	X(0), Y(0), Shape(' '), SortOrder(0), bCollide(false), Color{ 0,0,0,0 }, Size(32)
{
	//X = 0;		위와 같음
	//Y = 0;
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;

	SpriteSizeX = 1;
	SpriteSizeY = 1;
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	Color = { 0,0,0,0 };
	Size = 32;
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SpriteSizeX = 1;
	SpriteSizeY = 1;
}

AActor::~AActor()
{
	SDL_DestroyTexture(MyTexture);
	SDL_FreeSurface(MySurface);
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}


void AActor::LoadBMP(std::string Filename, SDL_Color Colorkey)
{
	//SSD>>RAM

	MySurface = SDL_LoadBMP(Filename.c_str());

	SDL_SetColorKey(MySurface, SDL_TRUE, SDL_MapRGBA(MySurface->format, Colorkey.r, Colorkey.g, Colorkey.b, Colorkey.a));

	MyTexture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);


}

void AActor::Render()
{
	//현재 액터 위치에 모양 출력
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	std::cout << Shape;
	if (bIsSprite)
	{
		SDL_RenderCopy(GEngine->MyRenderer
			, MyTexture
			, new SDL_Rect{ 0, 0, MySurface->w / SpriteSizeX, MySurface->h / SpriteSizeY }
			, new SDL_Rect{ X * Size,Y * Size,Size,Size
			});

	}
	else
	{
		SDL_RenderCopy(GEngine->MyRenderer
			, MyTexture
			, nullptr
			, new SDL_Rect{ X * Size,Y * Size,Size,Size
			});
	}

}

