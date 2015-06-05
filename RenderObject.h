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
	virtual void SetPosition(CLPoint2D& p){ m_curLogicPos = p; }
	virtual void CreateVAO(GLProgram* pro){ m_pShader = pro; }
	virtual bool CreateTexture(std::string& imageName){ return true; }
	virtual void Draw(){};
protected:
	CPoint2D m_curPos;
    CLPoint2D m_curLogicPos;
	GLuint m_iMeshBuffer;
	GLuint m_ivao;
	GLuint m_iTextureID;
	GLuint m_iTexLoc;
	GLuint m_iColorMaskID;
	GLuint m_iColorMaskLoc;
	GLProgram* m_pShader;
};

#endif
