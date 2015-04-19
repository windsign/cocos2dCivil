#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "cocos2d.h"

USING_NS_CC;

class CRenderObject
{
public:
	CRenderObject();
	virtual ~CRenderObject();
	virtual void SetPosition(CPoint2D& p);
protected:
	CPoint2D m_curPos;
	GLuint m_iMeshBuffer;
	GLuint m_ivao;
	GLProgram* m_pShader;
};

#endif
