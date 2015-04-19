#ifndef GAMETERRAINLAYER_H
#define GAMETERRAINLAYER_H
#include "cocos2d.h"

USING_NS_CC;


class CGameTerrainLayer : public Layer
{
public:
	CGameTerrainLayer(void);

	~CGameTerrainLayer(void);

	virtual bool init();

	CREATE_FUNC(CGameTerrainLayer);

	void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);

    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    void onDraw();
private:
	CustomCommand m_command;
};

#endif
