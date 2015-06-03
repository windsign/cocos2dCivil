#include "GameScene.h"
#include "PawnMgr.h"
#include "RenderWorld.h"
#include "MeshMgr.h"
#include "PawnTable.h"
#include "ActiveSkillTable.h"
#include "PassiveSkillTable.h"
#include "BattleEventHandler.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d::ui;

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

	srand(time(NULL));

    CCFileUtils::sharedFileUtils()->addSearchPath("./data/");
    
	m_pRenderWorld = new CRenderWorld;
	m_pRenderWorld->InitShaderProgram();

	GetMeshMgr()->Init();

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

	m_pEventHandler = new CBattleEventHandler;
	m_pEventHandler->Init(m_pPawnMgr, ePC_Blue);

	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	EventListenerTouchAllAtOnce* listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(CGameScene::onTouchesBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	GetPawnTable()->LoadTable();
	GetActiveSkillTable()->LoadTable();
	GetPassiveSkillTable()->LoadTable();

	m_pPawnMgr->CreateNewPawn(1);
	this->scheduleUpdate();
	return true;
}

void CGameScene::Clear()
{
	delete m_pRenderWorld;
	m_pRenderWorld = 0;

	delete m_pPawnMgr;
	m_pPawnMgr = 0;
}

void CGameScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	//
	std::vector<Touch*>::const_iterator itor;
	itor = touches.begin();
	const Vec2 touchLocation = (*itor)->getLocation();
	m_pEventHandler->OnClick(touchLocation.x, touchLocation.y);
}

void CGameScene::update(float frametime)
{
	//int i = 0;
	m_pEventHandler->Update(frametime);
}
