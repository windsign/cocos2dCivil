#ifndef SIXEDGERENDEROBJECT
#define SIXEDGERENDEROBJECT

#include "SixEdgeMath.h"
#include "cocos2d.h"

USING_NS_CC;

class CSixEdgeRenderObject : public CRenderObject
{
public:
	CSixEdgeRenderObject();
	~CSixEdgeRenderObject();
	void SetPosition(CPoint2D& p){m_wishPos = p;}
private:
	CPoint2D  m_wishPos;
};

#endif
