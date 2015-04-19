#ifndef PAWNMGR_H
#define PAWNMGR_H

class CPawn;

using namespace std;

class CPawnMgr
{
public:
	CPawnMgr();
	~CPawnMgr();
	CPawn* CreateNewPawn();
private:
//Pawns
	vector<CPawn*> m_vecPawns;
};
#endif
