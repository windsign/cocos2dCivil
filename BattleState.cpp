#include "BattleState.h"
#include "BattleEventHandler.h"

void State_TurnStart::Active()
{
	m_pEventHandler->DoAllStartBuff();
	m_pEventHandler->ChangeState(eBS_PlayerTurnStart);
}

void State_TurnStart::Update(float t)
{

}

void State_PlayerTurnStart::Active()
{
	//显示“我方回合开始”
	m_pEventHandler->ChangeState(eBS_WaitForClick);
}

void State_PlayerTurnStart::Update(float t)
{

}

void State_WaitForClick::Active()
{
	//可以自动选择一个可控制的Pawn
}

void State_WaitForClick::Update(float t)
{

}

void State_PawnClicked::Active()
{

}

void State_PawnClicked::Update(float t)
{

}

void State_PawnAttack::Active()
{

}

void State_PawnAttack::Update(float t)
{

}

void State_PawnMove::Active()
{

}

void State_PawnMove::Update(float t)
{

}

void State_PawnMoveEnd::Active()
{

}

void State_PawnMoveEnd::Update(float t)
{

}

void State_PlayerTurnEnd::Active()
{

}

void State_PlayerTurnEnd::Update(float t)
{

}

void State_TurnEnd::Active()
{

}

void State_TurnEnd::Update(float t)
{

}

void State_PawnDie::Active()
{

}

void State_PawnDie::Update(float t)
{

}

void State_PawnHurt::Active()
{

}

void State_PawnHurt::Update(float t)
{

}

