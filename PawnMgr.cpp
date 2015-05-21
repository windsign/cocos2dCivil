#include "PawnMgr.h"
#include "Pawn.h"
#include "RenderWorld.h"
#include "PawnTable.h"

CPawnMgr::CPawnMgr()
{
	m_iCurIndex = 1;
	m_pRenderWorld = 0;
}

CPawnMgr::~CPawnMgr()
{
}

CPawn* CPawnMgr::CreateNewPawn(int idx)
{
	CPawn* pn = new CPawn;
	if (pn)
	{
		pn->SetIndex(m_iCurIndex);
		m_iCurIndex++;

		CPawnTableElement* pe = GetPawnTable()->GetPawnElement(idx);
		pn->Init(m_pRenderWorld, pe);

		CLPoint2D pos(0, 0, false);
		pn->SetPos(pos);
	}

	return pn;
}

void CPawnMgr::Init(CRenderWorld* pRenderWorld)
{
	m_pRenderWorld = pRenderWorld;
}

CPawn* CPawnMgr::GetPawnIndexByLPos(CLPoint2D& lp)
{
	map<int, CPawn*>::iterator itor;
	for (itor = m_mapPawns.begin(); itor != m_mapPawns.end(); itor++)
	{
		CPawn* curPawn = (*itor).second;
		if (curPawn->GetPos() == lp)
		{
			return curPawn;
		}
	}
	return 0;
}
