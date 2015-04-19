#include "SixEdgeMath.h"
#include <memory.h>


resSixEdge::resSixEdge()
{
	memset(m_fPoint, 0, sizeof(m_fPoint));
}

resSixEdge CSixEdgeMath::GetPointByLogicPos(int x, int y, bool isOdd)
{
	//区分六边形地图的奇偶
	
	float off_y = y * 3 * m_fEdgeLength;
	float off_x = x * SQRT3 * m_fEdgeLength;
	
	if (!isOdd)
	{
		off_y += m_fEdgeLength * 1.5;
		off_x -= 0.5 * SQRT3 * m_fEdgeLength;
	}

	resSixEdge res;
	CPoint2D off_point(off_x, off_y);

	CPoint2D cur_point;
	for (int i = 0; i < 6; i++)
	{
		cur_point = m_MetaSixEdge.m_point[i];
		cur_point *= m_fEdgeLength;
		cur_point += off_point;
		res.m_fPoint[i * 2] = cur_point.x;
		res.m_fPoint[i * 2 + 1] = cur_point.y;
	}
	return res;
}

CPoint2D CSixEdgeMath::GetPoint(int x, int y, bool isOdd)
{
    float off_y = y * 3 * m_fEdgeLength;
    float off_x = x * SQRT3 * m_fEdgeLength;
    
    if (!isOdd)
    {
        off_y += m_fEdgeLength * 1.5;
        off_x -= 0.5 * SQRT3 * m_fEdgeLength;
    }
    
    CPoint2D rp(off_x, off_y);
    return rp;
}

CSixEdgeMath::CSixEdgeMath()
{
	m_fEdgeLength = 100.0f;
}


CSixEdgeMath::~CSixEdgeMath()
{
}


CMetaSixEdge::CMetaSixEdge()
{
	m_point[0] = CPoint2D(-SQRT3*0.5f, -0.5f);
	m_point[1] = CPoint2D(-SQRT3*0.5f, 0.5f);
	m_point[2] = CPoint2D(0.0f, 1.0f);
	m_point[3] = CPoint2D(SQRT3*0.5f, 0.5f);
	m_point[4] = CPoint2D(SQRT3*0.5f, -0.5f);
	m_point[5] = CPoint2D(0.0f, -1.0f);
}

CMetaSixEdge::~CMetaSixEdge()
{

}



CSixEdgeMath* GetSixEdgeMath()
{
	static CSixEdgeMath* g_pSixEdgeMath = new CSixEdgeMath;
	return g_pSixEdgeMath;
}
