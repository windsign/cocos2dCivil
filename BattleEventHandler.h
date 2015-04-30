#ifndef BATTLEEVENTHANDLER_H
#define BATTLEEVENTHANDLER_H

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
	PowerHitRes CalPowerHit(int attackPower, int attackDefence, int counterPower, int counterDefence);
	AttackHurtRes CalAttackHurt(PowerHitRes hitRes, int attackerHP, int counterHP, float fAttackPercent, float fcounterPercent);
private:
	CPawnMgr* m_pPawnMgr;
};

#endif