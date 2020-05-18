#pragma once
#include "CD3DApp.h"
class CGame01 : public CD3DApp
{
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	CGame01();
	~CGame01();
};

