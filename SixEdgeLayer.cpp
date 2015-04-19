#include "SixEdgeLayer.h"
#include "SixEdgeMath.h"

//const float g_sqrt3 = 1.732f;

CSixEdgeLayer::CSixEdgeLayer()
{
}


CSixEdgeLayer::~CSixEdgeLayer()
{
}

bool CSixEdgeLayer::init()
{
	if (!Layer::init()){
		return false;
	}
	GetSixEdgeMath()->SetDefaultEdgeLength(68.0f);
	return true;
}

void CSixEdgeLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	glLineWidth(1);

/*
	//画一个多边形
	ccDrawColor4B(0, 168, 0, 200);
	glLineWidth(1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			resSixEdge res = GetSixEdgeMath()->GetPointByLogicPos(i, j, true);
			CCPoint vertices[] = { ccp(res.m_fPoint[0], res.m_fPoint[1]),
				ccp(res.m_fPoint[2], res.m_fPoint[3]),
				ccp(res.m_fPoint[4], res.m_fPoint[5]),
				ccp(res.m_fPoint[6], res.m_fPoint[7]),
				ccp(res.m_fPoint[8], res.m_fPoint[9]),
				ccp(res.m_fPoint[10], res.m_fPoint[11]) };
			ccDrawPoly(vertices, 6, true);
		}
	}
 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			resSixEdge res = GetSixEdgeMath()->GetPointByLogicPos(i, j, false);
			CCPoint vertices[] = { ccp(res.m_fPoint[0], res.m_fPoint[1]),
				ccp(res.m_fPoint[2], res.m_fPoint[3]),
				ccp(res.m_fPoint[4], res.m_fPoint[5]),
				ccp(res.m_fPoint[6], res.m_fPoint[7]),
				ccp(res.m_fPoint[8], res.m_fPoint[9]),
				ccp(res.m_fPoint[10], res.m_fPoint[11]) };
			ccDrawPoly(vertices, 6, true);
		}
	}
  */

}


