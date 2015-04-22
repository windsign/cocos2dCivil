#include "GameScene.h"
#include "PawnMgr.h"
#include "RenderWorld.h"

CGameScene::CGameScene(void)
{
	m_pGameTerrainLayer = 0;
	m_pPawnsLayer = 0;
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
	m_pRenderWorld = new CRenderWorld;
	m_pRenderWorld->InitShaderProgram();

	m_pGameTerrainLayer = CGameTerrainLayer::create();
	if (m_pGameTerrainLayer == NULL)
	{
		return false;
	}
	this->addChild(m_pGameTerrainLayer);

	m_pPawnsLayer = CPawnsLayer::create();
	if (m_pPawnsLayer == NULL)
	{
		return false;
	}
	m_pPawnsLayer->SetScene(this, m_pRenderWorld);
	this->addChild(m_pPawnsLayer);

	m_pPawnMgr = new CPawnMgr;
	m_pPawnMgr->Init(m_pRenderWorld);
	return true;
}

void CGameScene::Clear()
{
	delete m_pRenderWorld;
	m_pRenderWorld = 0;

	delete m_pPawnMgr;
	m_pPawnMgr = 0;
}
