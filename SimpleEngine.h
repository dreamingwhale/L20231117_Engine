#include <vector>
#include <string>
#include "Actor.h"
#include "GameMode.h"
#pragma once
class UWorld;	//전방선언 : 앞에서 클래스를 찾아봐.
class AActor;
class AGameMode;
class AGameState;
//인클루드는 자원을 많이 잡아먹으므로 인클루드 대신 대부분 쓴다. 
class SimpleEngine
{
private:
	SimpleEngine();

public:
	virtual ~SimpleEngine();

	void Init();	//엔진 실행
	void Run();
	void Stop();
	void Term();	//엔진 종료
	void LoadLevel(std::string Filename);

	inline UWorld* GetWorld()const { return World; }
	static SimpleEngine* GetInstance()
	{
		//singletone
		if (Instance == nullptr)
		{
			Instance = new SimpleEngine();
		}
		return Instance;
	}

	static int KeyCode;
	static AGameState* GetGameState() { return GetInstance()->GameState; };
	static AGameMode* GetGameMode() { return GetInstance()->GameMode; };
protected:
	UWorld* World;
	bool IsRunning;
	//전방선언 방법2 class UWorld* uworld;

	void Input();
	void Tick();
	void Render();
	static SimpleEngine* Instance;
	class AGameMode* GameMode;
	class AGameState* GameState;
};
#define GEngine SimpleEngine::GetInstance()