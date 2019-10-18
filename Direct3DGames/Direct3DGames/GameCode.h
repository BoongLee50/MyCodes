#pragma once
#include "CD3DApp.h"
#include "Triangle.h"

class GameCode : public CD3DApp
{
	Triangle m_Triangle;

	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	GameCode(void);
	~GameCode(void);
};

