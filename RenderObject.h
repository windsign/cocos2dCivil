#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

class CRenderObject
{
public:
	CRenderObject();
	virtual ~CRenderObject();
	virtual void SetPosition(CPoint2D& p);
protected:
	CPoint2D m_curPos;
	int m_iMesh;
	int m_iTexture;

};

#endif
