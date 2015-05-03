#ifndef BATTLEEVENTHANDLER_H
#define BATTLEEVENTHANDLER_H

#include "Point2D.h"

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
	
private:
	CPawnMgr* m_pPawnMgr;
};

#endif
