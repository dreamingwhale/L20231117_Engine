#include "Player.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
}

APlayer::APlayer(int NewX, int NewY)
{
	Shape = 'P';
	SetX(NewX);
	SetY(NewY);
}

APlayer::~APlayer()
{
}

void APlayer::Tick(int KeyCode)
{
	//AActor::Tick(KeyCode);	//Super가 원래 c++에서는 존재하지 않음. 언리얼에는 존재
	__super::Tick(KeyCode);		//visual studio 전용 문법
	if (KeyCode == 'A' || KeyCode == 'a')
	{
		X--;
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		X++;
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		Y--;
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		Y++;
	}
}
