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
private:
//Pawns
	map<int, CPawn*> m_mapPawns;
	int m_iCurIndex;
};
#endif
