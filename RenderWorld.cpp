#include "RenderWorld.h"
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
