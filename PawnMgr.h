#ifndef PAWNMGR_H
#define PAWNMGR_H

#include <map>

class CPawn;

using namespace std;
class CRenderWorld;
class CPawnMgr
{
public:
	CPawnMgr();
	~CPawnMgr();
	CPawn* CreateNewPawn();
	void Init(CRenderWorld* pRenderWorld);
private:
//Pawns
	map<int, CPawn*> m_mapPawns;
	int m_iCurIndex;
	CRenderWorld* m_pRenderWorld;
};
#endif
