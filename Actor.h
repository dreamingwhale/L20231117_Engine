#pragma once
class AActor
{
public:
	int x;
	int y;

	AActor();
	~AActor();

	//virtual void BeginPlay()=0;를 통해 순수 가상 함수로 구현할 수 있다. => 재정의해서 구현해라라는 의미
	//c++는 다중 상속이 가능하기에 인터페이스를 따로 구현할 필요가 없다. 하지만 
	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
};

