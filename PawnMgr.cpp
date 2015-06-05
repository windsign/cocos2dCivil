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

		CPawnTableElement* pe = GetPawnTable()->GetPawnElement(idx);
		pn->Init(m_pRenderWorld, pe);

		CLPoint2D pos(0, 0, true);
		pn->SetPos(pos);
		pn->SetColor(ePC_Blue);
		//std::pair<int, CPawn*> new
		m_mapPawns.insert(make_pair(m_iCurIndex, pn));
		m_iCurIndex++;
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

CPawn* CPawnMgr::GetPawnByIndex(int idx)
{
	map<int, CPawn*>::iterator itor;
	itor = m_mapPawns.find(idx);
	if (itor != m_mapPawns.end())
	{
		return (itor)->second;
	}
	return NULL;
}
