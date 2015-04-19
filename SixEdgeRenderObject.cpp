#include "SixEdgeRenderObject.h"

CSixEdgeRenderObject::CSixEdgeRenderObject()
{
}

~CSixEdgeRenderObject::CSixEdgeRenderObject()
{
}

void SetPosition(CLPoint2D& p)
{
	m_logicPos = p;

	m_wishPos = GetSixEdgeMath()->GetPoint(p, p.o);
	
}
