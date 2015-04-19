#ifndef PAWN_H
#define PAWN_H

#include "Point2D.h"

class CPawn
{
public:

private:
//location
	CLPoint2D m_logicPoint;
	CPoint2D  m_curPos;
	CPoint2D  m_wishPos;
//fight
	int	m_iPower;
	int m_iHealth;
};

#endif
