#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerEnum.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	bool Init(EPlayerColor e);
	void SetPlayerColor(EPlayerColor e){ m_ePlayerColor = e; }
	EPlayerColor GetPlayerColor(){ return m_ePlayerColor; }
	void SetPlayerColor(EPlayerNation e){ m_ePlayerNation = e; }
	EPlayerNation GetPlayerNation(){ return m_ePlayerNation; }
private:
	EPlayerColor m_ePlayerColor;
	EPlayerNation m_ePlayerNation;
	int m_iScore;
	int m_iGold;
	int m_iIron;
	int m_iJewel;
	int m_iWind;
	int m_iEarth;
	int m_iFire;
	int m_iWater;
};

#endif
