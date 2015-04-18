#include "GameScene.h"

CGameScene::CGameScene(void)
{
	m_pGameTerrainLayer = 0;
}

CGameScene::~CGameScene(void)
{

}

bool CGameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	m_pGameTerrainLayer = CGameTerrainLayer::create();
	if (m_pGameTerrainLayer == NULL)
	{
		return false;
	}
	this->addChild(m_pGameTerrainLayer);
	return true;
}