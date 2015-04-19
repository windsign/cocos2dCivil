#ifndef PAWNLAYER_H
#define PAWNLAYER_H
#include "cocos2d.h"

USING_NS_CC;


class CPawnsLayer : public Layer
{
public:
	CPawnsLayer(void);

	~CPawnsLayer(void);

	virtual bool init();

	CREATE_FUNC(CPawnsLayer);

	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);

	virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
	void onDraw();
private:
	CustomCommand m_command;
};

#endif