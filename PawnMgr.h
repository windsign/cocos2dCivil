#ifndef PAWNMGR_H
#define PAWNMGR_H

#include <map>
#include "Point2D.h"

class CPawn;

using namespace std;
class CRenderWorld;
class CPawnMgr
{
public:
	CPawnMgr();
	~CPawnMgr();
	CPawn* CreateNewPawn(int idx);
	void Init(CRenderWorld* pRenderWorld);
	CPawn* GetPawnIndexByLPos(CLPoint2D& lp);
private:
//Pawns
	map<int, CPawn*> m_mapPawns;
	int m_iCurIndex;
	CRenderWorld* m_pRenderWorld;
};
#endif
