#ifndef CSIXEDGELAYER_H
#define CSIXEDGELAYER_H

#include "cocos2d.h"

USING_NS_CC;
class CRenderWorld;
class CSixEdgeLayer : public Layer
{
public:
	CSixEdgeLayer();
	~CSixEdgeLayer();

	virtual bool init();

	CREATE_FUNC(CSixEdgeLayer);
	void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
	void SetRenderWorld(CRenderWorld* p);

private:
	CRenderWorld*	m_pRenderWorld;
};

#endif

