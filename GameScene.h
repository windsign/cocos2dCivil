#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "GameTerrainLayer.h"

USING_NS_CC;

class CGameScene : public Scene{
public:
	CGameScene(void);

	~CGameScene(void);

	virtual bool init();

	CREATE_FUNC(CGameScene);

	//void PreloadMusic();

	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);

private:
	CGameTerrainLayer* m_pGameTerrainLayer;
	//	CSixEdgeLayer* m_sixEdgeLayer;

};

#endif
