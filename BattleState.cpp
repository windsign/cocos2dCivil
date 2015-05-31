#include "BattleState.h"
#include "BattleEventHandler.h"
#include "PawnMgr.h"
#include "Pawn.h"

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
	//��ʾ���ҷ��غϿ�ʼ��
	m_pEventHandler->ChangeState(eBS_WaitForClick);


}

void State_PlayerTurnStart::Update(float t)
{

}

void State_WaitForClick::Active()
{
	//�����Զ�ѡ��һ���ɿ��Ƶ�Pawn
}

void State_WaitForClick::Update(float t)
{
	if (m_pEventHandler->m_bTouch)
	{
		CPawn* pPawn = m_pEventHandler->GetPawnMgr()->GetPawnIndexByLPos(m_pEventHandler->m_touchPoint);

		if (pPawn != 0)
		{
			//��ʾ�ƶ��������Ϣ

			if (pPawn->GetNation() == )
				m_pEventHandler->SetCurClickPawnIdx(pPawn->GetIndex());
			m_pEventHandler->ChangeState(eBS_PawnClicked);
			return;
		}

	}

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

