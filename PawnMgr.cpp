#include "PawnMgr.h"
#include "Pawn.h"
#include "RenderWorld.h"

CPawnMgr::CPawnMgr()
{
	m_iCurIndex = 1;
}

CPawnMgr::~CPawnMgr()
{
}

CPawn* CPawnMgr::CreateNewPawn()
{
	CPawn* pn = new CPawn;
	if (pn)
	{
		pn->SetIndex(m_iCurIndex);
	}
	pn->Init();
	CLPoint2D pos(0, 0, false);
	pn->SetPos(pos);
	return pn;
}
