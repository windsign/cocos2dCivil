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
	m_pShader = pro;
	glGenVertexArrays(1, &m_ivao);
	glBindVertexArray(m_ivao);
	GetMeshMgr()->BindBuffer(eMT_SixEdgeShape);

	GLuint posLocation = glGetAttribLocation(pro->getProgram(), "a_position");
	glEnableVertexAttribArray(posLocation);
	glVertexAttribPointer(posLocation, 2, GL_FLOAT, GL_FALSE, sizeof(CVertex), (GLvoid*)offsetof(CVertex, m_pos));

	GLuint uvLocation = glGetAttribLocation(pro->getProgram(), "a_texCoord");
	glEnableVertexAttribArray(uvLocation);
	glVertexAttribPointer(uvLocation, 2, GL_FLOAT, GL_FALSE, sizeof(CVertex), (GLvoid*)offsetof(CVertex, m_uv));

	m_iUniformPosLoc = glGetUniformLocation(pro->getProgram(), "u_pos");
	m_iTexLoc = glGetUniformLocation(pro->getProgram(), "CC_Texture1");

	glBindVertexArray(0);
	CHECK_GL_ERROR_DEBUG();

}

void CSixEdgeRenderObject::Draw()
{
	glBindVertexArray(m_ivao);

	float uPos[] = { 50.0f, 50.0f, 0, 0 };
	uPos[0] += m_wishPos.x;
	uPos[1] += m_wishPos.y;
	glUniform4fv(m_iUniformPosLoc, 1, uPos);

	GL::bindTexture2DN(0, m_iTextureID);
	glUniform1i(m_iTextureID, 0);

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, (GLvoid*)0);

	CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 6);

	CHECK_GL_ERROR_DEBUG();

}

bool CSixEdgeRenderObject::CreateTexture(std::string& imageName)
{
	m_iTextureID = Director::getInstance()->getTextureCache()->addImage(imageName.c_str())->getName();
	CHECK_GL_ERROR_DEBUG();
	return true;
}
