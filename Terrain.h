#ifndef TERRAIN_H
#define TERRAIN_H

#include "Point2D.h"
#include "TerrainType.h"
#include "BuildingType.h"
#include <vector>

struct OneTerrainCell
{
     CLPoint2D m_logicPosition;
     EWeatherType m_eWeather;
     ETerrainType m_iTerrain;               //地形
     EVegetationType m_iVegetation;            //植被   
     EResourceType m_iResource;              //永久地形资源，奇观
     EBuildingType m_iBuild;                 //人工建筑   
};

class CTerrain
{
public:

private:
     std::vector<std::vector<OneTerrainCell> > m_odderrainCell;
     std::vector<std::vector<OneTerrainCell> > m_evenTerrainCell;
     
     int m_iOddHeight;
     int m_iOddWidth;
     int m_iEvenHeight;
     int m_iEvenWidth;
     
     //20150506
     bool LoadTerrain(const char* terrainName);
     OneTerrainCell* GetTerrainCell(CLPoint2D& point);
};

#endif
