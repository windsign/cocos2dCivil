#ifndef PAWN_H
#define PAWN_H

#include "Point2D.h"
#include "PawnAttribute.h"
#include "PawnTable.h"
#include "PlayerEnum.h"

class CRenderWorld;
class CPawn
{
public:
	CPawn();
	~CPawn();
	void Update(float t);
	void SetPos(CLPoint2D &lp);
	CLPoint2D GetPos(){ return m_logicPoint; }
	void SetIndex(int idx){ m_iIndex = idx; }
	int GetIndex(){ return m_iIndex; }
	void Init(CRenderWorld* renderWorld, CPawnTableElement* pe);
	void SetColor(EPlayerColor e){ m_eColor = e; }
	EPlayerColor GetColor(){ return m_eColor; }

private:
	int m_iIndex;
	EPlayerColor m_eColor;
//location
	CLPoint2D m_logicPoint;
//fight
	int	m_iPower;
	int m_iHealth;
//renderobject
	int m_iRenderIdx;
	CRenderWorld* m_pRenderWorld;
//
	CPawnTableElement* m_pPawnElement;
	CPawnAttribute m_attribute;
	
};

#endif
