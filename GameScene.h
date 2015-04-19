#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "GameTerrainLayer.h"
#include "PawnsLayer.h"

USING_NS_CC;

class CPawnMgr;
class CRenderWorld;

class CGameScene : public Scene{
public:
	CGameScene(void);

	~CGameScene(void);

	virtual bool init();

	CREATE_FUNC(CGameScene);

	//void PreloadMusic();

	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);

private:
	//layer
	CGameTerrainLayer*	m_pGameTerrainLayer;
	CPawnsLayer*		m_pPawnsLayer;
private:
	//logic 
	CPawnMgr*			m_pPawnMgr;
	//	CSixEdgeLayer* m_sixEdgeLayer;

};

#endif
