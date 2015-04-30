#ifndef PAWN_H
#define PAWN_H

#include "Point2D.h"
#include "PawnAttribute.h"

class CRenderWorld;
class CPawn
{
public:
	CPawn();
	~CPawn();
	void Update(float t);
	void SetPos(CLPoint2D &lp);
	void SetIndex(int idx){ m_iIndex = idx; }
	int GetIndex(){ return m_iIndex; }
	void Init(CRenderWorld* renderWorld);
private:
	int m_iIndex;
//location
	CLPoint2D m_logicPoint;
//fight
	int	m_iPower;
	int m_iHealth;
//renderobject
	int m_iRenderIdx;
	CRenderWorld* m_pRenderWorld;
//
	CPawnAttribute m_attribute;
};

#endif
