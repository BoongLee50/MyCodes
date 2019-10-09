#pragma once
#include "CD3DApp.h"

class GameCode
{
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	GameCode(void);
	~GameCode(void);
};

