#pragma once
#include "CD3DApp.h"
//#include "Triangle.h"
#include <D3dx9shape.h>
#include "Axis.h"
//#include "Cube.h"

class GameCode : public CD3DApp
{
	//Triangle m_Triangle;
	//CCube m_Cube;

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;
	CAxis m_Axis;

	LPD3DXMESH m_pBoxMesh;
	LPD3DXMESH m_pSphereMesh;
	LPD3DXMESH m_pTeapotMesh;
	LPD3DXMESH m_pCylinderMesh;
	
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	GameCode(void);
	~GameCode(void);
};

