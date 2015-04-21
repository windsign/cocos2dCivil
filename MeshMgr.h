#ifndef MESHMGR_H
#define MESHMGR_H

#include "cocos2d.h"
#include "Vertex.h"

USING_NS_CC;

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
	CMeshMgr();
	~CMeshMgr();
	CMesh* GetMesh(EMeshType emt);
	void _CreateMesh(EMeshType emt);
	void _CreateSixEdgeShapeMesh();
	bool BindBuffer(EMeshType emt);
private:
	CMesh m_Meshs[eMT_ALL];
};

CMeshMgr* GetMeshMgr();
#endif