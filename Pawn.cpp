#include "Pawn.h"
#include "RenderWorld.h"

CPawn::CPawn()
{
	m_iPower = 1;
	m_iHealth = 1;
	m_iRenderIdx = 0;
	m_pRenderWorld = 0;
}

CPawn::~CPawn()
{

}

void CPawn::Update(float t)
{

}

void CPawn::SetPos(CLPoint2D &lp)
{
	m_logicPoint = lp;
	
}

void CPawn::Init(CRenderWorld* renderWorld)
{
	m_pRenderWorld = renderWorld;
}