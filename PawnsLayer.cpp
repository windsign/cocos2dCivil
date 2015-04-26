#include "PawnsLayer.h"
#include "RenderWorld.h"
#include "GameScene.h"

CPawnsLayer::CPawnsLayer(void)
{

}


CPawnsLayer::~CPawnsLayer(void)
{

}

bool CPawnsLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void CPawnsLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	//m_pGameScene->onTouchesBegan(touches, unused_event);

}

void CPawnsLayer::visit(Renderer *renderer, const Mat4& transform, uint32_t parentFlags)
{
	Layer::visit(renderer, transform, parentFlags);
	m_command.init(_globalZOrder);
	m_command.func = CC_CALLBACK_0(CPawnsLayer::onDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&m_command);
}

void CPawnsLayer::onDraw()
{
	auto glProgram = m_pRenderWorld->GetShaderProgram(eST_Pawn);
	glProgram->use();
	glProgram->setUniformsForBuiltins();

	m_pRenderWorld->Draw(eST_Pawn);
}

void CPawnsLayer::SetScene(CGameScene* pGS, CRenderWorld* pRW)
{
	m_pGameScene = pGS;
	m_pRenderWorld = pRW;
	GLProgram* p_glProgram = m_pRenderWorld->GetShaderProgram(eST_Pawn);
	setGLProgram(p_glProgram);
}
