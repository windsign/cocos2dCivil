#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "cocos2d.h"
#include "Point2D.h"

USING_NS_CC;

class CRenderObject
{
public:
	CRenderObject();
	virtual ~CRenderObject();
	virtual void SetPosition(CPoint2D& p){ m_curPos = p; };
	virtual void CreateVAO(GLProgram* pro){};
	virtual void Draw(){};
protected:
	CPoint2D m_curPos;
	GLuint m_iMeshBuffer;
	GLuint m_ivao;
	GLProgram* m_pShader;
};

#endif
