#include <iostream>
#include "SimpleEngine.h"
#include <algorithm>
using namespace std;


int main()
{
	SimpleEngine* MyEngine = SimpleEngine::GetInstance();

	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	return 0;
}