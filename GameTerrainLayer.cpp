#include "GameTerrainLayer.h"


CGameTerrainLayer::CGameTerrainLayer(void)
{

}


CGameTerrainLayer::~CGameTerrainLayer(void)
{

}

bool CGameTerrainLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void CGameTerrainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{


}

void CGameTerrainLayer::visit(Renderer *renderer, const Mat4& transform, uint32_t parentFlags)
{
    Layer::visit(renderer, transform, parentFlags);
    m_command.init(_globalZOrder);
    m_command.func = CC_CALLBACK_0(CGameTerrainLayer::onDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&m_command);
}

void CGameTerrainLayer::onDraw()
{

}
