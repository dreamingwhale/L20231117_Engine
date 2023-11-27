#include <vector>
#include <string>
#include "Actor.h"
#include "GameMode.h"
#pragma once
class UWorld;	//���漱�� : �տ��� Ŭ������ ã�ƺ�.
class AActor;
class AGameMode;
class AGameState;
//��Ŭ���� �ڿ��� ���� ��Ƹ����Ƿ� ��Ŭ��� ��� ��κ� ����. 
class SimpleEngine
{
private:
	SimpleEngine();

public:
	virtual ~SimpleEngine();

	void Init();	//���� ����
	void Run();
	void Stop();
	void Term();	//���� ����
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
	//���漱�� ���2 class UWorld* uworld;

	void Input();
	void Tick();
	void Render();
	static SimpleEngine* Instance;
	class AGameMode* GameMode;
	class AGameState* GameState;
};
#define GEngine SimpleEngine::GetInstance()