#include "Terrain.h"

bool CTerrain::LoadTerrain(const char* terrainName)
{

}

CSceneEntity* CTerrain::GetSceneEntity(CLPoint2D& point)
{
     if(point.e)
     {
          if(point.x > m_iEvenWidth || point.x < 0 || point.y < 0 || point.y > m_iEvenHeight)
               return 0;
          return &m_evenTerrainCell[point.x][point.y];
     }
     else
     {
          if(point.x > m_iOddWidth || point.x < 0 || point.y < 0 || point.y > m_iOddHeight)
               return 0;
          return &m_oddTerrainCell[point.x][point.y];
     }
}
