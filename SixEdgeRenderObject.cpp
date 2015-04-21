#include "SixEdgeRenderObject.h"

CSixEdgeRenderObject::CSixEdgeRenderObject()
{
}

CSixEdgeRenderObject::~CSixEdgeRenderObject()
{
}

void CSixEdgeRenderObject::SetPosition(CLPoint2D& p)
{
	m_logicPos = p;
	m_wishPos = GetSixEdgeMath()->GetPoint(p, p.e);
	
}
