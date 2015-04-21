#ifndef MESHMGR_H
#define MESHMGR_H

#include "cocos2d.h"

enum EMeshType
{
	eMT_SixEdgeShape,
	eMT_ALL
};

class CMesh
{
public:
	CMesh(){ m_iVertexBuffer = 0; m_iIndexBuffer = 0; }
	~CMesh();
	GLuint m_iVertexBuffer;
	GLuint m_iIndexBuffer;
};

class CMeshMgr
{
public:

private:
	
};
#endif