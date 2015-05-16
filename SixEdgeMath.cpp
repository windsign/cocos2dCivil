#include "SixEdgeMath.h"
#include <memory.h>


resSixEdge::resSixEdge()
{
	memset(m_fPoint, 0, sizeof(m_fPoint));
}

CLPoint2D evenAdjacentOffset[6] =
{
	{ -1, 0, true },
	{ -1, -1, false },
	{ 0, -1, false },
	{ 1, 0, true },
	{ -1, 1, false },
	{ 0, 1, false }
};

CLPoint2D oddAdjacentOffset[6] =
{
	{ -1, 0, true },
	{ 0, -1, false },
	{ 1, -1, false },
	{ 1, 0, true },
	{ 1, 1, false },
	{ 0, 1, false }
};

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

CPoint2D CSixEdgeMath::GetPoint(CLPoint2D& p, bool isEven)
{
    float off_y = p.y * 3 * m_fEdgeLength;
    float off_x = p.x * SQRT3 * m_fEdgeLength;
    
	if (!isEven)
    {
        off_y += m_fEdgeLength * 1.5;
        off_x += 0.5 * SQRT3 * m_fEdgeLength;
    }
    
    CPoint2D rp(off_x, off_y);
    return rp;
}

void CSixEdgeMath::GetAdjacentCell(CLPoint2D& p, CLPoint2D res_point[])
{
	if (p.e)
	{
		for (int i = 0; i < 6; i++)
			res_point[i] = p + evenAdjacentOffset[i];
	}
	else
	{
		for (int i = 0; i < 6; i++)
			res_point[i] = p + oddAdjacentOffset[i];
	}
}

CSixEdgeMath::CSixEdgeMath()
{
	m_fEdgeLength = 20.0f;
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

void CSixEdgeMath::GetCell(int sx, int sy, CLPoint2D& resLogicPos, CPoint2D& resPos)
{
	float f_xtimes = sx / (SQRT3 * m_fEdgeLength);
	int ox = (int)f_xtimes;
	int ex = (int)(f_xtimes + 0.5f);

	float f_ytimes = sy / (3 * m_fEdgeLength);
	int oy = (int)f_ytimes;
	int ey = (int)(f_ytimes + 0.5);

	CLPoint2D o_lpoint(ox, oy, false);
	CLPoint2D e_lpoint(ex, ey, true);

	CPoint2D o_point = GetPoint(o_lpoint, false);
	CPoint2D e_point = GetPoint(e_lpoint, true);

	CPoint2D scenePoint(sx, sy);
	float d_o = o_point.Distance(scenePoint);
	float d_e = e_point.Distance(scenePoint);

	if (d_o < d_e)
    {
		resLogicPos = o_lpoint;
        resPos = o_point;
    }
    else
    {
        resLogicPos = e_lpoint;
        resPos = e_point;
    }
}


