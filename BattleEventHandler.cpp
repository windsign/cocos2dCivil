#include "BattleEventHandler.h"
#include "Pawn.h"
#include "PawnMgr.h"
#include "cocos2d.h"
#include "SixEdgeMath.h"

void CBattleEventHandler::Init(CPawnMgr* p, EPlayerColor localplayercolor)
{
	m_pPawnMgr = p;
	m_eLocalPlayerColor = localplayercolor;

	m_states[eBS_TurnStart] = new State_TurnStart;
	m_states[eBS_TurnStart]->SetContext(this);

	m_states[eBS_PlayerTurnStart] = new State_PlayerTurnStart;
	m_states[eBS_PlayerTurnStart]->SetContext(this);

	m_states[eBS_WaitForClick] = new State_WaitForClick;
	m_states[eBS_WaitForClick]->SetContext(this);

	m_states[eBS_PawnClicked] = new State_PawnClicked;
	m_states[eBS_PawnClicked]->SetContext(this);

	m_states[eBS_PawnAttack] = new State_PawnAttack;
	m_states[eBS_PawnAttack]->SetContext(this);

	m_states[eBS_PawnHurt] = new State_PawnHurt;
	m_states[eBS_PawnHurt]->SetContext(this);

	m_states[eBS_PawnDie] = new State_PawnDie;
	m_states[eBS_PawnDie]->SetContext(this);

	m_states[eBS_PawnMove] = new State_PawnMove;
	m_states[eBS_PawnMove]->SetContext(this);

	m_states[eBS_PawnMoveEnd] = new State_PawnMoveEnd;
	m_states[eBS_PawnMoveEnd]->SetContext(this);

	m_states[eBS_PlayerTurnEnd] = new State_PlayerTurnEnd;
	m_states[eBS_PlayerTurnEnd]->SetContext(this);

	m_states[eBS_TurnEnd] = new State_TurnEnd;
	m_states[eBS_TurnEnd]->SetContext(this);

}

PowerHitRes CBattleEventHandler::CalNormalPowerHit(int attackPower, int attackDefence, int counterPower, int counterDefence)
{
	float P = (CCRANDOM_0_1() * 100) / 100.0f;
	float cP = (CCRANDOM_0_1() * 100) / 100.0f;
	PowerHitRes res;
	res.fAttackValue = (24 + 12 * P)*(pow((attackPower / counterDefence + 3),4) / 512 + 0.5f);
	res.fCounterAttackValue = (24 + 12 * cP)*(pow((counterPower / attackDefence + 3),4) / 512 + 0.5f);

	return res;
}

AttackHurtRes CBattleEventHandler::CalNormalAttackHurt(PowerHitRes hitRes, int attackerHP, int counterHP, float fAttackPercent, float fcounterPercent)
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

void CBattleEventHandler::DoAllStartBuff()
{

}

void CBattleEventHandler::ChangeState(EBattleState es)
{
	m_eLastState = m_eCurState;
	m_eCurState = es;
	m_states[m_eCurState]->Active();
}

void CBattleEventHandler::Update(float t)
{
	m_states[m_eCurState]->Update(t);
	Flush();
}

void CBattleEventHandler::OnClick(int sx, int sy)
{
	CPoint2D pos;
	GetSixEdgeMath()->GetCell(sx, sy, m_touchPoint, pos);
	m_bTouch = true;
}

void CBattleEventHandler::Flush()
{
	m_bTouch = false;
}



