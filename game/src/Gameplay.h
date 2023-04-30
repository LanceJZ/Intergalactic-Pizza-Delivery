#pragma once
#include "Common.h"

class Gameplay : Common
{
public:
	Gameplay();
	virtual ~Gameplay();

	bool Initialize();
	bool BeginRun();

	virtual void Input();
	virtual void Update(float deltaTime);
	virtual void Draw();

private:
	void PlayerHit();

};

