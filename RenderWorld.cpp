#include "RenderWorld.h"
#include "RenderObject.h"
#include <memory>

int CRenderWorld::AddSixEdgeRenderObject()
{
	m_iCurRenderObjectIndex++;
	return m_iCurRenderObjectIndex;
}

void CRenderWorld::Init()
{

}


void CRenderWorld::InitShaderProgram()
{
	m_pGLProgram[eST_Pawn] = new GLProgram;
	m_pGLProgram[eST_Pawn]->initWithFilenames("simplevs.vs", "simplefs.fs");
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
	for (itor = m_mapRenderObject.begin(); itor != m_mapRenderObject.end(); itor++)
	{
		cur = (itor)->second;
		if (cur)
		{
			cur->Draw();
		}
	}
}

