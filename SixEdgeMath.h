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
    CPoint2D GetPoint(int x, int y, bool isOdd = true);
	void SetDefaultEdgeLength(float l){ m_fEdgeLength = l;}
    float GetDefaultEdgeLength(){return m_fEdgeLength;}
private:
	float m_fEdgeLength;
	CMetaSixEdge m_MetaSixEdge;
};

CSixEdgeMath* GetSixEdgeMath();
#endif
