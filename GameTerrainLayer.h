#ifndef GAMETERRAINLAYER_H
#define GAMETERRAINLAYER_H
#include "cocos2d.h"

USING_NS_CC;


class CGameTerrainLayer : public Layer
{
public:
	CGameTerrainLayer(void);

	~CGameTerrainLayer(void);

	virtual bool init();

	CREATE_FUNC(CGameTerrainLayer);

	//void loadingDone(Node* pNode);

	//virtual void keyBackClicked();//
	//virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	//bool isHaveSaveFile();

	//void getHighestHistorySorce();

	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);

};

#endif