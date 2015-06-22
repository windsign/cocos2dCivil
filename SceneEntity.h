
#include "TerrainType.h"
#include "Point2D.h"
struct OneTerrainCell
{
     CLPoint2D m_logicPosition;
     EWeatherType m_eWeather;
     ETerrainType m_iTerrain;               //地形
     EVegetationType m_iVegetation;            //植被   
     EResourceType m_iResource;              //永久地形资源，奇观
     EBuildingType m_iBuild;                 //人工建筑   
};

class CRenderWorld;
class CSceneEntity
{
public:
	CSceneEntity();
	~CSceneEntity();
	void Init(CRenderWorld* renderWorld);
private:
	OneTerrainCell m_TerrainCellInfo;
	CRenderWorld*  m_pRenderWorld;
	int 		   m_iRenderIdx;
};

