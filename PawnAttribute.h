#ifndef PAWNATTRIBUTE_H
#define PAWNATTRIBUTE_H
#include "PawnTable.h"
enum EPawnAttribute
{
	ePA_Attack,
	ePA_Defence,
	ePA_MoveCount,
	ePA_AttackCount,
	ePA_All
};

class CPawn;
class CPawnAttribute
{
public:
	CPawnAttribute();
	~CPawnAttribute();
	bool CanAct();
	int GetAttribute(EPawnAttribute e);
	void Init(CPawn* pawn, CPawnTableElement* pe);
private:
	int m_iBaseAttribute[ePA_All];
	int m_iAddAttribute[ePA_All];
	float m_fMultiAttribute[ePA_All];
	CPawn* m_pPawn;
};

#endif