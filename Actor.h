#pragma once
class AActor
{
public:

	AActor();
	AActor(int NewX, int NewY);
	virtual ~AActor();

	//virtual void BeginPlay()=0;�� ���� ���� ���� �Լ��� ������ �� �ִ�. => �������ؼ� �����ض��� �ǹ�
	//c++�� ���� ����� �����ϱ⿡ �������̽��� ���� ������ �ʿ䰡 ����. ������ 
	virtual void BeginPlay();
	virtual void Tick(int KeyCode);
	virtual void Render();
	//accessor
	int GetX() const { return X; };
	int GetY() const { return Y; };

	inline void SetX(int NewX) { X = NewX; };
	inline void SetY(int NewY) { Y = NewY; };

protected:
	int X;
	int Y;

	char Shape;
};

