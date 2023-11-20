#include <vector>
#include <string>
#pragma once
class UWorld;	//���漱�� : �տ��� Ŭ������ ã�ƺ�.
class AActor;
				//��Ŭ���� �ڿ��� ���� ��Ƹ����Ƿ� ��Ŭ��� ��� ��κ� ����. 
class SimpleEngine
{
public :
	SimpleEngine();
	virtual ~SimpleEngine();

	void Init();	//���� ����
	void Run();
	void Stop();
	void Term();	//���� ����
	void LoadLevel(std::string Filename);

	inline UWorld* GetWorld()const { return World; };

protected:
	UWorld* World;
	bool IsRunning;
	//���漱�� ���2 class UWorld* uworld;

	int Input();
	void Tick(int KeyCode);
	void Render();
};

