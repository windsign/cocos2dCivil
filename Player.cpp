#include "Player.h"

CPlayer::CPlayer()
{
	m_iScore = 0;
	m_iGold = 100;
	m_iIron = 100;
	m_iJewel = 0;
	m_iWind = 0;
	m_iEarth = 0;
	m_iFire = 0;
	m_iWater = 0;
}

CPlayer::~CPlayer()
{

}

bool CPlayer::Init(EPlayerColor e)
{
	m_ePlayerColor = e;
	return true;
}
