#ifndef CSIXEDGEMATH_H
#define CSIXEDGEMATH_H

#include "Point2D.h"
#define  SQRT3 1.732f

struct resSixEdge
{
	resSixEdge();
	float m_fPoint[12];
};

class CMetaSixEdge
{
public:
	CMetaSixEdge();
	~CMetaSixEdge();
	CPoint2D m_point[6];
};

class CSixEdgeMath
{
public:
	CSixEdgeMath();
	~CSixEdgeMath();

	resSixEdge GetPointByLogicPos(int x, int y, bool isOdd = true);
    CPoint2D GetPoint(CLPoint2D& p, bool isEven = true);
	void SetDefaultEdgeLength(float l){ m_fEdgeLength = l;}
    float GetDefaultEdgeLength(){return m_fEdgeLength;}
	void GetCell(int sx, int sy, CLPoint2D& resLogicPos, CPoint2D& resPos);
	void GetAdjacentCell(CLPoint2D& p, CLPoint2D respoint[]);
private:
	float m_fEdgeLength;
	CMetaSixEdge m_MetaSixEdge;
};

CSixEdgeMath* GetSixEdgeMath();
#endif
