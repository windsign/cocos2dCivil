#include "SixEdgeRenderObject.h"
#include "MeshMgr.h"

CSixEdgeRenderObject::CSixEdgeRenderObject()
{
	
}

CSixEdgeRenderObject::~CSixEdgeRenderObject()
{
}

void CSixEdgeRenderObject::SetPosition(CLPoint2D& p)
{
	m_logicPos = p;
	m_wishPos = GetSixEdgeMath()->GetPoint(p, p.e);
	
}

void CSixEdgeRenderObject::CreateVAO(GLProgram* pro)
{
	glGenVertexArrays(1, &m_ivao);
	glBindVertexArray(m_ivao);
	GetMeshMgr()->BindBuffer(eMT_SixEdgeShape);

	GLuint posLocation = glGetAttribLocation(pro->getProgram(), "a_position");
	glEnableVertexAttribArray(posLocation);
	glVertexAttribPointer(posLocation, 2, GL_FLOAT, GL_FALSE, sizeof(CVertex), (GLvoid*)offsetof(CVertex, m_pos));

	GLuint uvLocation = glGetAttribLocation(pro->getProgram(), "a_color");
	glEnableVertexAttribArray(uvLocation);
	glVertexAttribPointer(uvLocation, 2, GL_FLOAT, GL_FALSE, sizeof(CVertex), (GLvoid*)offsetof(CVertex, m_uv));

	CHECK_GL_ERROR_DEBUG();

}

void CSixEdgeRenderObject::Draw()
{
	glBindVertexArray(m_ivao);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, (GLvoid*)0);

	CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 6);

	CHECK_GL_ERROR_DEBUG();

}
