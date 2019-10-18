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
	m_Triangle.OnInit(m_pd3dDevice);
}

void GameCode::OnRender()
{
	m_Triangle.OnRender();
}

void GameCode::OnUpdate()
{

}

void GameCode::OnRelease()
{
	m_Triangle.OnRelease();
}