#include "SceneEntity.h"

CSceneEntity::CSceneEntity()
{
	m_pRenderWorld = 0;
	m_iRenderIdx = -1;
}

CSceneEntity::~CSceneEntity()
{

}

void CSceneEntity::Init(CRenderWorld* renderWorld)
{
	m_pRenderWorld = renderWorld;
}
