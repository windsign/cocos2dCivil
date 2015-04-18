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


