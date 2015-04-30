#include "BattleEventHandler.h"
#include "Pawn.h"
#include "PawnMgr.h"
#include "cocos2d.h"

void CBattleEventHandler::Init(CPawnMgr* p)
{

}

PowerHitRes CBattleEventHandler::CalPowerHit(int attackPower, int attackDefence, int counterPower, int counterDefence)
{
	float P = (CCRANDOM_0_1() * 100) / 100.0f;
	float cP = (CCRANDOM_0_1() * 100) / 100.0f;
	PowerHitRes res;
	res.fAttackValue = (24 + 12 * P)*(pow((attackPower / counterDefence + 3),4) / 512 + 0.5f);
	res.fCounterAttackValue = (24 + 12 * cP)*(pow((counterPower / attackDefence + 3),4) / 512 + 0.5f);

	return res;
}

AttackHurtRes CBattleEventHandler::CalAttackHurt(PowerHitRes hitRes, int attackerHP, int counterHP, float fAttackPercent, float fcounterPercent)
{
	float hpAttackPercent = attackerHP*0.00333f + 0.667f;
	hpAttackPercent += (fAttackPercent / 100.0f);

	float hpCounterPercent = counterHP*0.00333f + 0.667f;
	hpCounterPercent += (fcounterPercent / 100.0f);

	AttackHurtRes res;
	res.fAttackHurtValue = hitRes.fAttackValue*hpAttackPercent;
	res.fCounterHurtValue = hitRes.fCounterAttackValue*hpCounterPercent;

	return res;

}
