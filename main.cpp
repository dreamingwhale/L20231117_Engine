#include <iostream>
#include "SimpleEngine.h"
int main()
{
	SimpleEngine* MyEngine = new SimpleEngine();
	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();
	return 0;
}