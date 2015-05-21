#ifndef BATTLEEVENTHANDLER_H
#define BATTLEEVENTHANDLER_H

#include "Point2D.h"
#include "BattleStateEnum.h"
#include "BattleState.h"

struct PowerHitRes
{
	float fAttackValue;
	float fCounterAttackValue;
};

struct AttackHurtRes
{
	float fAttackHurtValue;
	float fCounterHurtValue;
};


class CPawnMgr;

class CBattleEventHandler
{
public:
	void Init(CPawnMgr* p);
	PowerHitRes CalNormalPowerHit(int attackPower, int attackDefence, int counterPower, int counterDefence);
	AttackHurtRes CalNormalAttackHurt(PowerHitRes hitRes, int attackerHP, int counterHP, float fAttackPercent, float fcounterPercent);
	void DoAllStartBuff();
	void ChangeState(EBattleState es);
	void Update(float t);
	void OnClick(int sx, int sy);

	CPawnMgr* GetPawnMgr(){ return m_pPawnMgr; }
	void SetCurClickPawn(int idx){ m_iCurClickedPawnIdx = idx; }
	int GetCurClickPawn(){ return m_iCurClickedPawnIdx; }
	void Flush();
public:
	bool m_bTouch;
	CLPoint2D m_touchPoint;
private:
	CPawnMgr* m_pPawnMgr;
	EBattleState m_eCurState;
	EBattleState m_eLastState;
	State_Base m_states[eBS_All];
	int m_iCurClickedPawnIdx;

};

#endif
