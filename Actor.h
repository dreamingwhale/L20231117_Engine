#pragma once
class AActor
{
public:
	int x;
	int y;

	AActor();
	~AActor();

	//virtual void BeginPlay()=0;�� ���� ���� ���� �Լ��� ������ �� �ִ�. => �������ؼ� �����ض��� �ǹ�
	//c++�� ���� ����� �����ϱ⿡ �������̽��� ���� ������ �ʿ䰡 ����. ������ 
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
};

