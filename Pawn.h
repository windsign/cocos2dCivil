#ifndef PAWN_H
#define PAWN_H

#include "Point2D.h"

class CPawn
{
public:
	void Update(float t);
	void SetPos(CLPoint2D &lp);
private:
//location
	CLPoint2D m_logicPoint;
//fight
	int	m_iPower;
	int m_iHealth;
//renderobject
	int m_iRenderIdx;
};

#endif
