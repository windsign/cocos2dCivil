#include "RenderWorld.h"
#include "RenderObject.h"
#include "SixEdgeRenderObject.h"
#include <memory>

using namespace std;

int CRenderWorld::AddSixEdgeRenderObject(std::string& imageName)
{
	m_iCurRenderObjectIndex++;
	CRenderObject* p = new CSixEdgeRenderObject;
	p->CreateVAO(m_pGLProgram[eST_Pawn]);
	p->CreateTexture(imageName);
	pair<int, CRenderObject*> new_RO(m_iCurRenderObjectIndex, p);
	m_mapRenderObject[eST_Pawn].insert(new_RO);
	return m_iCurRenderObjectIndex;
}

void CRenderWorld::Init()
{

}


void CRenderWorld::InitShaderProgram()
{
	m_pGLProgram[eST_Pawn] = new GLProgram;
	m_pGLProgram[eST_Pawn]->initWithFilenames("texturevs.vs", "texturefs.fs");
	m_pGLProgram[eST_Pawn]->link();
	m_pGLProgram[eST_Pawn]->updateUniforms();
	
	CHECK_GL_ERROR_DEBUG();
}


CRenderWorld::CRenderWorld()
{
	m_iCurRenderObjectIndex = 0;
	memset(m_pGLProgram, 0, sizeof(m_pGLProgram));
}

CRenderWorld::~CRenderWorld()
{

}

GLProgram* CRenderWorld::GetShaderProgram(EShaderType e)
{
	return m_pGLProgram[e]; 
}

void CRenderWorld::Draw(EShaderType eST)
{
	map<int, CRenderObject*>::iterator itor;
	CRenderObject* cur = 0;
	for (itor = m_mapRenderObject[eST].begin(); itor != m_mapRenderObject[eST].end(); itor++)
	{
		cur = (itor)->second;
		if (cur)
		{
			cur->Draw();
		}
	}
}

void CRenderWorld::SetRenderObjectPos(int idx, EShaderType est)
{
	map<int, CRenderObject*>::iterator itor;
	itor = m_mapRenderObject[est].find(idx);
	if (itor != m_mapRenderObject[est].end())
	{
        CLPoint2D point(0, 0, true);
		(*itor).second->SetPosition(point);
	}
}

