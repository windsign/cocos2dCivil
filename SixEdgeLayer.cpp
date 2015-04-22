#include "SixEdgeLayer.h"
#include "SixEdgeMath.h"

//const float g_sqrt3 = 1.732f;
#include "RenderWorld.h"

CSixEdgeLayer::CSixEdgeLayer()
{
}


CSixEdgeLayer::~CSixEdgeLayer()
{
}

bool CSixEdgeLayer::init()
{
	if (!Layer::init()){
		return false;
	}
	GetSixEdgeMath()->SetDefaultEdgeLength(68.0f);
	return true;
}

void CSixEdgeLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{

	/*
	glLineWidth(1);


	//画一个多边形
	ccDrawColor4B(0, 168, 0, 200);
	glLineWidth(1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			resSixEdge res = GetSixEdgeMath()->GetPointByLogicPos(i, j, true);
			CCPoint vertices[] = { ccp(res.m_fPoint[0], res.m_fPoint[1]),
				ccp(res.m_fPoint[2], res.m_fPoint[3]),
				ccp(res.m_fPoint[4], res.m_fPoint[5]),
				ccp(res.m_fPoint[6], res.m_fPoint[7]),
				ccp(res.m_fPoint[8], res.m_fPoint[9]),
				ccp(res.m_fPoint[10], res.m_fPoint[11]) };
			ccDrawPoly(vertices, 6, true);
		}
	}
 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			resSixEdge res = GetSixEdgeMath()->GetPointByLogicPos(i, j, false);
			CCPoint vertices[] = { ccp(res.m_fPoint[0], res.m_fPoint[1]),
				ccp(res.m_fPoint[2], res.m_fPoint[3]),
				ccp(res.m_fPoint[4], res.m_fPoint[5]),
				ccp(res.m_fPoint[6], res.m_fPoint[7]),
				ccp(res.m_fPoint[8], res.m_fPoint[9]),
				ccp(res.m_fPoint[10], res.m_fPoint[11]) };
			ccDrawPoly(vertices, 6, true);
		}
	}
  */

}

void CSixEdgeLayer::SetRenderWorld(CRenderWorld* p)
{
	m_pRenderWorld = p;
	GLProgram* p_glProgram = m_pRenderWorld->GetShaderProgram(eST_Pawn);
	setGLProgram(p_glProgram);
}

void CSixEdgeLayer::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
	Layer::visit(renderer, parentTransform, parentFlags);
	m_command.init(_globalZOrder);
	m_command.func = CC_CALLBACK_0(CSixEdgeLayer::onDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&m_command);
}

void CSixEdgeLayer::onDraw()
{
	auto glProgram = m_pRenderWorld->GetShaderProgram(eST_Pawn);
	glProgram->use();
	glProgram->setUniformsForBuiltins();
}

