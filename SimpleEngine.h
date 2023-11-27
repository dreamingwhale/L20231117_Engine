#include <vector>
#include <string>
#include "Actor.h"
#pragma once
class UWorld;	//���漱�� : �տ��� Ŭ������ ã�ƺ�.
class AActor;
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

protected:
	UWorld* World;
	bool IsRunning;
	//���漱�� ���2 class UWorld* uworld;

	void Input();
	void Tick();
	void Render();
	static SimpleEngine* Instance;
};
#define GEngine SimpleEngine::GetInstance()