#ifndef TERRAIN_H
#define TERRAIN_H

#include "Point2D.h"
#include "TerrainType.h"
#include "BuildingType.h"
#include <vector>
#include "SceneEntity.h"

class CTerrain
{
public:

private:
     std::vector<std::vector<CSceneEntity> > m_oddTerrainCell;
     std::vector<std::vector<CSceneEntity> > m_evenTerrainCell;
     
     int m_iOddHeight;
     int m_iOddWidth;
     int m_iEvenHeight;
     int m_iEvenWidth;
     
     //20150506
     bool LoadTerrain(const char* terrainName);
     CSceneEntity* GetSceneEntity(CLPoint2D& point);
};

#endif
