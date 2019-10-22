#include "stdafx.h"
#include "GameCode.h"

GameCode::GameCode(void)
{
	
}


GameCode::~GameCode(void)
{

}

void GameCode::OnInit()
{
	RECT rect;
	D3DVIEWPORT9 vp;					//ºäÆ÷Æ®, Ã¢ÀÇ Å©±â¸¦ Á¤ÇÔ
	GetClientRect(m_hWnd, &rect);

	vp.X = 0;
	vp.Y = 0;
	vp.Width = rect.right - rect.left;  // ÁÂÇ¥°³³äÀÌ ¾Æ´Ï¶ó Å©±â °³³ä 800, 600 °è»êµÊ
	vp.Height = rect.bottom - rect.top;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;

	m_Eye.x = 5.0f;
	m_Eye.y = 8.0f;
	m_Eye.z = -10.0f;

	m_At.x = 0.0f;
	m_At.y = 0.0f;
	m_At.z = 0.0f;

	m_Up.x = 0.0f;
	m_Up.y = 1.0f;
	m_Up.z = 0.0f;

	D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
	m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
	m_pd3dDevice->SetViewport(&vp);

	m_Axis.OnInit(m_pd3dDevice);

	D3DXCreateBox(m_pd3dDevice, 2.0f, 2.0f, 2.0f, &m_pBoxMesh, NULL);
	D3DXCreateSphere( m_pd3dDevice, 3.0f, 30, 10, &m_pSphereMesh, NULL );   
	D3DXCreateTeapot( m_pd3dDevice, &m_pTeapotMesh, NULL );
	D3DXCreateCylinder(m_pd3dDevice, 2.0f, 2.0f, 5.0f, 30, 10, &m_pCylinderMesh, NULL);

	//m_Triangle.OnInit(m_pd3dDevice);
	//m_Cube.OnInit(m_pd3dDevice);
}

void GameCode::OnRender()
{
	m_Axis.OnRender();

	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	m_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	m_pBoxMesh->DrawSubset(0);
	m_pSphereMesh->DrawSubset(0);
	m_pTeapotMesh->DrawSubset(0);	
	m_pCylinderMesh->DrawSubset(0);

	//m_Cube.OnRender();
	//m_Triangle.OnRender();
}

void GameCode::OnUpdate()
{

}

void GameCode::OnRelease()
{
	m_pCylinderMesh->Release();
	m_pTeapotMesh->Release();
	m_pSphereMesh->Release();
	m_pBoxMesh->Release();

	m_Axis.OnRelease();

	//m_Cube.OnRelease();
	//m_Triangle.OnRelease();
}