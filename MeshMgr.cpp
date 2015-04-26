#include "MeshMgr.h"
#include "Point2D.h"
#include "SixEdgeMath.h"


CMesh::~CMesh()
{

}


CMeshMgr::CMeshMgr()
{

}

CMeshMgr::~CMeshMgr()
{

}

CPoint2D uvCoordinate[] = 
{
	{ 0.067f, 0.75f },
	{ 0.067f, 0.25f },
	{0.5f, 0.0f},
	{0.933f, 0.25f},
	{0.933f, 0.75f},
	{ 0.5f, 1.0f }
};

void CMeshMgr::Init()
{
	_CreateMesh(eMT_SixEdgeShape);
}


void CMeshMgr::_CreateMesh(EMeshType emt)
{
	switch (emt)
	{
		case eMT_SixEdgeShape:
		{
			_CreateSixEdgeShapeMesh();
		}
		break;
	}
}

void CMeshMgr::_CreateSixEdgeShapeMesh()
{
	CMesh& cm = m_Meshs[eMT_SixEdgeShape];
	resSixEdge res;
	res = GetSixEdgeMath()->GetPointByLogicPos(0, 0, true);

	float *pf = &res.m_fPoint[0];
	CVertex seMesh[] =
	{
		{ { pf[0], pf[1] }, { uvCoordinate[0].x, uvCoordinate[0].y } },
		{ { pf[2], pf[3] }, { uvCoordinate[1].x, uvCoordinate[1].y } },
		{ { pf[4], pf[5] }, { uvCoordinate[2].x, uvCoordinate[2].y } },
		{ { pf[6], pf[7] }, { uvCoordinate[3].x, uvCoordinate[3].y } },
		{ { pf[8], pf[9] }, { uvCoordinate[4].x, uvCoordinate[4].y } },
		{ { pf[10], pf[11] }, { uvCoordinate[5].x, uvCoordinate[5].y } }
	};

	glGenBuffers(1, &cm.m_iVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, cm.m_iVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(seMesh), seMesh, GL_STATIC_DRAW);

	GLubyte indexVBO[] = { 0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5 };

	glGenBuffers(1, &cm.m_iIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cm.m_iIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexVBO), indexVBO, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	CHECK_GL_ERROR_DEBUG();
}

bool CMeshMgr::BindBuffer(EMeshType emt)
{
	if (emt >= eMT_ALL)
	{
		return false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_Meshs[emt].m_iVertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Meshs[emt].m_iIndexBuffer);
	CHECK_GL_ERROR_DEBUG();
	return true;
}

CMeshMgr* g_pMeshMgr = 0;
CMeshMgr* GetMeshMgr()
{
	if (g_pMeshMgr == 0)
	{
		g_pMeshMgr = new CMeshMgr();
	}
	return g_pMeshMgr;
}
