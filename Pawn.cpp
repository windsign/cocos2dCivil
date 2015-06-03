#include "Pawn.h"
#include "RenderWorld.h"

CPawn::CPawn()
{
	m_iPower = 1;
	m_iHealth = 1;
	m_iRenderIdx = 0;
	m_pRenderWorld = 0;
	m_pPawnElement = 0;
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
	m_pRenderWorld->SetRenderObjectPos(m_iRenderIdx, eST_Pawn, lp);
}

void CPawn::Init(CRenderWorld* renderWorld, CPawnTableElement* pe)
{
	if (pe == 0)
	{
		return;
	}
	m_pPawnElement = pe;
	m_attribute.Init(this, pe);
	m_pRenderWorld = renderWorld;
	std::string image_name = pe->m_Image + ".png";
	m_iRenderIdx = m_pRenderWorld->AddSixEdgeRenderObject(image_name);
}