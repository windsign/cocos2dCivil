#include "PawnsLayer.h"


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

}