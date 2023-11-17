#include "SimpleEngine.h"
#include "World.h"

SimpleEngine::SimpleEngine()
{
	UWorld* World = new UWorld;
	bool IsRunning = true;
}

SimpleEngine::~SimpleEngine()
{
}

void SimpleEngine::Init()
{
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{

		//World;
	}
}

void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
}
