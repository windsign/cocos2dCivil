#include "PawnAttribute.h"
#include "Pawn.h"
#include <memory>

CPawnAttribute::CPawnAttribute()
{
	memset(m_iBaseAttribute, 0, sizeof(m_iBaseAttribute));
	memset(m_iAddAttribute, 0, sizeof(m_iAddAttribute));
	for (int i = 0; i < ePA_All; i++)
	{
		m_fMultiAttribute[i] = 1.0f;
	}
	m_pPawn = 0;
}

CPawnAttribute::~CPawnAttribute()
{

}

void CPawnAttribute::Init(CPawn* pawn, CPawnTableElement* pe)
{
	m_iBaseAttribute[ePA_AttackCount] = pe->m_iAttackCount;
	m_iBaseAttribute[ePA_MoveCount] = pe->m_iMoveCount;
	m_iBaseAttribute[ePA_Attack] = pe->m_iAttack;
	m_iBaseAttribute[ePA_Defence] = pe->m_iDefence;
	m_pPawn = pawn;
}

int CPawnAttribute::GetAttribute(EPawnAttribute e)
{
	int res = (m_iBaseAttribute[e] + m_iAddAttribute[e])*m_fMultiAttribute[e];
	return res;
}

bool CPawnAttribute::CanAct()
{
	bool canMove = GetAttribute(ePA_MoveCount) > 0;
	bool canAttack = GetAttribute(ePA_AttackCount) > 0;
	return (canMove&&canAttack);
}
