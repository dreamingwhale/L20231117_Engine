#include <iostream>
#include "SimpleEngine.h"
#include <algorithm>
#include <fstream>
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2Main")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	MyEngine->LoadLevel("Data/level01.smap");
	MyEngine->Run();

	return 0;

}