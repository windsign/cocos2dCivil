#ifndef SIXEDGERENDEROBJECT
#define SIXEDGERENDEROBJECT

#include "SixEdgeMath.h"
#include "RenderObject.h"

class CSixEdgeRenderObject : public CRenderObject
{
public:
	CSixEdgeRenderObject();
	~CSixEdgeRenderObject();
	void SetPosition(CLPoint2D& p);
	void CreateVAO(GLProgram* pro);
	void Draw();
private:
	CPoint2D  m_wishPos;
	CLPoint2D m_logicPos;
};

#endif
