#pragma once
#include "CD3DApp.h"
//#include "Triangle.h"
#include "Axis.h"
#include "Cube.h"

class GameCode : public CD3DApp
{
	//Triangle m_Triangle;

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;
	CAxis m_Axis;
	CCube m_Cube;
	
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	GameCode(void);
	~GameCode(void);
};

