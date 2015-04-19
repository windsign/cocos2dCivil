#include "PawnMgr.h"
#include "Pawn.h"


CPawnMgr::CPawnMgr()
{
}

CPawnMgr::~CPawnMgr()
{
}

CPawn* CPawnMgr::CreateNewPawn()
{
	CPawn* pn = new CPawn;

	return pn;
}
